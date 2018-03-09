#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <stdlib.h>

char palavraSecreta[20];
char chutesDados[26];
int numeroTentativa = 0;

//abertura do jogo
void abertura(){
	printf("#=======================#\n");
	printf("#=====Jogo da Forca=====#\n");
	printf("#=======================#\n");
}

//Função de chute, existe a entrada de uma letra 
//adiciona a letra no vetor, correspondente a tentativa 
//utilizando ponteiro
void chute(){
	char chute;
		
	printf("\nQual letra? ");
	scanf(" %c", &chute);
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

int enforcou(){
	
	int erros = 0;
	for (int i = 0; i < numeroTentativa; ++i){
		int acertou = 0;
		for (int j = 0; j < strlen(palavraSecreta); i++){
			if(chutesDados[i] == palavraSecreta[j]){
				acertou = 1;
				break;
			}
		}
		printf("Acertou: %d\n", acertou);

		if(acertou == 0){
			erros++;
		}		
		printf("Numero de erros: %d\n", erros);
	}

	return erros>=5;
}

void desenhaForca(){
	printf("Voce ja deu %d chute(s)\n", numeroTentativa);

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

	f = fopen("palavras.txt", "r");
	if(f == 0){
		printf("Falha no arquivo, jogo encerrado!\n\n");
		exit(1);
	}

}

int main(){
	
	abertura();
	escolhePalavra();

	do{

		desenhaForca();
		chute();
	}while(!ganhou() && !enforcou());
		
	return 0;
}
