#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

#define TAMANHO_PALAVRA 20

int ERROS_PERMITIDOS;
char palavraSecreta[TAMANHO_PALAVRA];
char chutesDados[26];
int numeroTentativa = 0;
int pontos = 0;

//abertura do jogo
void abertura(){
	printf("#=======================#\n");
	printf("#=====Jogo da Forca=====#\n");
	printf("#=======================#\n");
}


//Função de chute, existe a entrada de uma letra 
//adiciona a letra no vetor, correspondente a tentativa 
//utilizando ponteiro
int verificaChute(char chute){
	return chute < 65 || chute > 90;
}


void escolheNivel(){
	int nivel;

	printf("\nQual nivel de dificuldade deseja escolher?\n");
	printf("1) Facil 2) Medio 3) Dificil\n");
	scanf("%d", &nivel);

	if(nivel == 1){
		ERROS_PERMITIDOS = 11;
	}else if(nivel == 2){
		ERROS_PERMITIDOS = 7;
	}else{
		ERROS_PERMITIDOS = 5;
	}

}

void chute(){
	char chute;
	
	while(verificaChute(chute)){
		printf("\nQual letra? ");
		scanf(" %c", &chute);

		if(verificaChute(chute)){
			printf("Apenas letras de A-Z maiusculo\n");
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

	if(ERROS_PERMITIDOS == 14){
		pontos++;
	}else if(ERROS_PERMITIDOS == 7){
		pontos+=2;
	}else{
		pontos+=3;
	}
	return 1;
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
		printf(" |           %c    \n", (errou>2 ? '|' : ' '));
		printf(" |          %c %c  \n", (errou>3 ? '/' : ' '),(errou>3 ? '\\' : ' '));
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

	f = fopen("palavras.txt", "r");
	
	if(f == 0){
		printf("Falha no arquivo, jogo encerrado!\n\n");
		exit(1);
	}
	fscanf(f, "%d", &numeroPalavras);

	srand(time(0));

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
		printf("Parabens!!! Voce venceu");
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
}
int main(){
	
	char again;
	abertura();
	do{
		escolhePalavra();
		escolheNivel();

		do{		
			desenhaForca();
			chute();
		}while(!ganhou() && !enforcou());

		veredito();

		printf("\n\nDeseja jogar novamente? <s/n>\n");
		scanf(" %c", &again);

		resetaJogo();
	}while(again == 's');

	printf("%d", enforcou());

	if(pontos != 0){
       FILE *f;
	   char nome[30];
	   

	   f = fopen("ranking.txt", "a");

	   printf("Digite o nome do vencedor: \n");
	   scanf("%s", nome);

	   fprintf(f, "%s %d\n", nome, pontos);

	   fclose(f);
	}
}
