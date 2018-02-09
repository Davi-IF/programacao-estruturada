#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
	printf("",setlocale(LC_ALL,"")); 
	
	int semente = time(NULL);
	srand(semente);
	int chute, numeroSecreto = rand() % 100;
	int acertou=0, numeroTentativas=0, pontos=1000;
	int nivel, totalTentativas;
	
	printf("*************************\n");
	printf("***Jogo de Adivinhação***\n");
	printf("*************************\n\n");
	
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Fácil (2) Média (3) Difícil \n\n");
	
	printf("Escolha: ");
	scanf("%d", &nivel);
	
	switch(nivel){
		case 1:
			totalTentativas = 20;
			break;
		case 2:
			totalTentativas = 15;
			break;
		default:
			totalTentativas = 6;
			break;
	}
	int i;
	for ( i = 1; i<=totalTentativas; i++){
		printf("***************************\n");
		printf("Você está na tentativa: %i\n",numeroTentativas);
		printf("***************************\n");
		printf("Você tem %i pontos\n", pontos);
		printf("***************************\n\n");
		printf("Digite o numero do seu chute: ");
		scanf("%i",&chute);
		printf("\nNumero: %i\n", chute);

		acertou = chute == numeroSecreto;
		pontos -=abs((numeroSecreto - chute)/2);
	
		if(acertou){
				printf("*******************\n");
				printf("\nAcerto Mizeravi!\n");
				printf("*******************\n\n");
				break;
		}else{
			
			printf("\nErroooooooooW!!!\n");
				
			if(chute > numeroSecreto){
				printf("Numero digitado é maior que o numero secreto!\n\n");
			}else{
				printf("Numero digitado é menor que o numero secreto!\n\n");
			}
		}
		numeroTentativas++;
	}
	if(acertou){
		printf("Você terminou com %i pontos\n",pontos);
		printf("Fim de jogo!\n");
	}else{
		printf("Você perdeu!!! Seu troxa, mais sorte na proxima\n");
		printf("Fim de jogo!\n");
	}
	
	return 0;
}
