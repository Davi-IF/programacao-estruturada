#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

#define TAMANHO_PALAVRA 20

int ERROS_PERMITIDOS;
char palavraSecreta[TAMANHO_PALAVRA];
char chutesDados[26];
char nome[30];
int numeroTentativa = 0;
int pontos = 0;

//abertura do jogo
void abertura(){
	system("cls");
	printf("#=======================#\n");
	printf("#=====Jogo da Forca=====#\n");
	printf("#=======================#\n\n");
}

//Função de chute, existe a entrada de uma letra 
//adiciona a letra no vetor, correspondente a tentativa 
//utilizando ponteiro
int verificaChute(char chute){
	return chute < 65 || chute > 90;
}


void escolheNivel(){
	int nivel;
	do{
		printf("\nQual nivel de dificuldade deseja escolher?\n");
		printf("1) Facil 2) Medio 3) Dificil\n");
		scanf("%d", &nivel);

		if(nivel == 1){
			ERROS_PERMITIDOS = 11;
		}else if(nivel == 2){
			ERROS_PERMITIDOS = 7;
		}else if(nivel == 3){
			ERROS_PERMITIDOS = 4;
		}else{
			printf("Numero invalido!\n");
		}
	}while(nivel<1 || nivel >3);

}

void chute(){
	char chute;
	
	while(verificaChute(chute)){
		printf("\nQual letra? ");
		scanf(" %c", &chute);

		if(verificaChute(chute)){
			printf("Apenas letras de A-Z maiusculas\n");
		}
	}
	chutesDados[numeroTentativa] = chute;
	numeroTentativa++;
}
//Função que verifica a letra chutada, e vê se ela corresponde
//a palavra do vetor
//vetor == ponteiro;
int jachutou(char letra){
	int achou = 0;
	for(int y=0; y < numeroTentativa; y++){
		if(chutesDados[y] == letra){
			achou = 1;
			break;
		}
	}
	return achou;
}

int ganhou(){

	for(int i = 0; i < strlen(palavraSecreta); i++){
		if(!jachutou(palavraSecreta[i])){
			return 0;
		}
	}
	return 1;
}

void pontuacao(){

	if(ERROS_PERMITIDOS == 11){
		pontos++;
	}else if(ERROS_PERMITIDOS == 7){
		pontos+=2;
	}else{
		pontos+=3;
	}
}

void ranking(){
	FILE *f;
	int tamanhoRank;

	f = fopen("ranking.txt", "a");

	printf("Digite o nome do vencedor: \n");
	scanf("%s", nome);
	printf("\nNome:%s\nPontos: %d\n",nome, pontos);
	fprintf(f, "%s %d \n", nome, pontos);

	fclose(f);

	f = fopen("totalRanking.txt", "r");
	fscanf(f, "%d", &tamanhoRank);
	fclose(f);

	tamanhoRank++;

	f = fopen("totalRanking.txt", "w");
	fprintf(f, "%04d\n", tamanhoRank);
	fclose(f);
}

int enforcou(){
	return numeroDeErros() >= ERROS_PERMITIDOS;
}

void desenhaForca(){
	int errou = numeroDeErros();

	if(ERROS_PERMITIDOS == 7){
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (errou>0 ? '(' : ' '), (errou>0 ? '_' : ' '),(errou>0 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (errou>2 ? '/' : ' '),(errou>1 ? '|' : ' '), (errou>3 ? '\\' : ' '));
		printf(" |           %c    \n", (errou>1 ? '|' : ' '));
		printf(" |          %c %c  \n", (errou>4 ? '/' : ' '),(errou>5 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");
	} else if (ERROS_PERMITIDOS == 11 ){
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (errou>0 ? '(' : ' '), (errou>1 ? '_' : ' '),(errou>2 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (errou>4 ? '/' : ' '),(errou>5 ? '|' : ' '), (errou>6 ? '\\' : ' '));
		printf(" |           %c    \n", (errou>7 ? '|' : ' '));
		printf(" |          %c %c  \n", (errou>8 ? '/' : ' '),(errou>9 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");	
	}else{
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (errou>0 ? '(' : ' '), (errou>0 ? '_' : ' '),(errou>0 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (errou>1 ? '/' : ' '),(errou>1 ? '|' : ' '), (errou>1 ? '\\' : ' '));
		printf(" |           %c    \n", (errou>1 ? '|' : ' '));
		printf(" |          %c %c  \n", (errou>2 ? '/' : ' '),(errou>2 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");
	}

	printf("\n\n");

	for(int x = 0; x < strlen(palavraSecreta); x++){

		char letra = palavraSecreta[x];

		if(jachutou(letra)){
			printf("%c ", palavraSecreta[x]);
		}else{
			printf("_ ");
		}
	}
	printf("\n");
}

void escolhePalavra(){

	FILE* f;
	int numeroPalavras;

	f = fopen("numeroDePalavras.txt", "r");
	
	if(f == 0){
		printf("Falha no arquivo, jogo encerrado!\n\n");
		exit(1);
	}
	fscanf(f, "%d", &numeroPalavras);
	fclose(f);

	srand(time(0));

	f = fopen("palavras.txt", "r");
	if(f == 0){
		printf("Falha no arquivo, jogo encerrado!\n\n");
		exit(1);
	}
	int randomico = rand() % numeroPalavras; 

	for(int i = 0; i <= randomico; i++){
		fscanf(f, "%s", palavraSecreta);
	}

	fclose(f);
}

int numeroDeErros(){
	int erros = 0;

	for (int i = 0; i < numeroTentativa; ++i){
		int acertou = 0;
		for (int j = 0; j < strlen(palavraSecreta); j++){
			if(chutesDados[i] == palavraSecreta[j]){
				acertou = 1;
				break;
			}
		}
		if(acertou == 0){
			erros++;
		}		
	}

	return erros;
}

void veredito(){
	if(ganhou()){
		printf("Parabens!!! Voce venceu!\n");
		pontuacao();
	}else{
		printf("Que pena! Voce perdeu\n");
		printf("A palavra era: %s\n", palavraSecreta);
	}
}


void resetaJogo(){
	for (int i = 0; i < strlen(chutesDados); ++i){
			chutesDados[i] = ' ';
	}
	numeroTentativa = 0;
	system("cls");
}

int contemPalavra(char* palavraNova){
	FILE* f;
	int totalDePalavras;

	f = fopen("numeroDePalavras.txt", "r");
	fscanf(f, "%d", &totalDePalavras);

	fclose(f);

	f = fopen("palavras.txt", "r");
	
	for(int i = 0; i<totalDePalavras; i++){
		char palavraLista[30];
		fscanf(f, "%s", &palavraLista);

		if(strcmp(palavraNova, palavraLista) == 0){
			return 1;
		}
	}

	return 0;
}

void novaPalavra(){
	char palavraNova[30];
	int novoNumeroPalavras;


	printf("Por favor %s\nDigite uma nova palavra\npara o nosso banco de dados: \n", nome);

	scanf("%s", palavraNova);

	if(contemPalavra(palavraNova)){
		printf("\nDesculpe %s\nEssa palavra ja existe em nosso banco de dados\n\n", nome);
		system("pause");
		system("cls");
	}else{
		for(int i = 0; palavraNova[i]; i++){
			if(palavraNova[i] < 65 || palavraNova[i] > 90){
				while(palavraNova[i] < 65 || palavraNova[i] > 90){
					printf("Nome invalido, por favor so use letras maiusculas\n");
					scanf("%s", palavraNova);
					
					if(contemPalavra(palavraNova)){
					printf("\nDesculpe %s\nEssa palavra ja existe em nosso banco de dados\n\n", nome);
					system("pause");
					system("cls");
					return;
					}
				}
			}
		}

		FILE* f;

		f = fopen("palavras.txt","a");
		fprintf(f, "%s\n", palavraNova);

		fclose(f);

		f = fopen("numeroDePalavras.txt", "r");
	    fscanf(f, "%d", &novoNumeroPalavras);
	    fclose(f);

	    novoNumeroPalavras++;
	    f = fopen("numeroDePalavras.txt", "w");
	    fprintf(f, "%04d\n", novoNumeroPalavras);
	    fclose(f);
	}
}

void regras(){
	printf(" Ola seja bem vindo ao Jogo da Forca!!!\n\n");
	printf(" Como voce ja deve ter jogado, o jogo da forca trata de voce\n");
	printf(" Chutar letras para tentar achar nossa palavra secreta\n");
	printf(" Mas nosso jogo tem algumas coisas a mais\n");
	printf(" Voce podera escolher o nivel de dificuldade, sendo eles:\n\n");
	printf(" Facil(11 chances e 1 ponto)\n Medio(7 chances e 2 pontos)\n Dificil(4 chances e pontos)\n\n");
	printf(" Caso consiga ganhar, voce podera colocar seu nome em nosso glorioso ranking\n");
	printf(" Tambem, pode nos ajudar e formular novas palavras para nosso banco de dados\n");
	printf(" ATENCAO: em todo o jogo so sao aceitas letras maiusculas, entao, ative o CAPS LOCK E...\n");
	printf(" DIVIRTA-SE!!!\n\n");
	system("pause");
	system("cls");
}

void verRanking(){

	char nomeRank[30];
    int pontuacaoRank;
    int tamanhoRank;

	FILE* f;
	f = fopen("totalRanking.txt", "rb");
	fscanf(f,"%d",&tamanhoRank);
	fclose(f);
    if(tamanhoRank == 0){
       printf("Lista vazia\n\n");
    }else{
		f = fopen("ranking.txt", "rb");
		printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\xBA       RANKING      \xBA\n");
		printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n");
		printf("\xBA NOME      \xBA PONTOS \xBA\n");
		printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

       	for(int i = 0; i < tamanhoRank; i++){
        	fscanf(f, "%s %d", nomeRank, &pontuacaoRank);
        	printf(" %s -------> %d\n", nomeRank, pontuacaoRank);
        }

        printf("\n");
        fclose(f);
   }

   system("pause");
   system("cls");
   
}

int main(){
	
	char again;
	int menu;

	do{
		abertura();
		printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\xBA MENU \xBA\n");
		printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
		printf("1) Jogo\n");
		printf("2) Regras\n");
		printf("3) Ranking\n");
		printf("4) Exit\n");
		
		scanf("%d", &menu);
		system("cls");
		if(menu == 1){
			do{
				escolhePalavra();
				abertura();
				escolheNivel();

				do{		
					desenhaForca();
					chute();
				}while(!ganhou() && !enforcou());

				veredito();
				printf("\n*********************************\n");
				printf("**Deseja jogar novamente? <s/n>**\n");
				printf("*********************************\n");
				scanf(" %c", &again);
				resetaJogo();
			}while(again == 's' || again == 'S');

			if(pontos > 0){
				char quest;

		    	ranking();
		    	printf("Deseja digitar um nova palavra? <s/n>\n");
		    	scanf(" %c", &quest);
		    	if(quest == 's' || quest == 'S'){
		    		novaPalavra();
		    	}
			}
		}else if(menu == 2){
			regras();
		}else if(menu == 3){
			verRanking();
		}

		pontos = 0;
	}while(menu != 4);	

}