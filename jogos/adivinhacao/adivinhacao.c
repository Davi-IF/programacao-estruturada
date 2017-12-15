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
	printf("***Jogo de Adivinha��o***\n");
	printf("*************************\n\n");
	
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) F�cil (2) M�dia (3) Dif�cil \n\n");
	
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
		printf("Voc� est� na tentativa: %i\n",numeroTentativas);
		printf("***************************\n");
		printf("Voc� tem %i pontos\n", pontos);
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
				printf("Numero digitado � maior que o numero secreto!\n\n");
			}else{
				printf("Numero digitado � menor que o numero secreto!\n\n");
			}
		}
		numeroTentativas++;
	}
	if(acertou){
		printf("Voc� terminou com %i pontos\n",pontos);
		printf("Fim de jogo!\n");
	}else{
		printf("Voc� perdeu!!! Seu troxa, mais sorte na proxima\n");
	}
	
	return 0;
}
