#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
	printf("",setlocale(LC_ALL,"")); 
	
	int chute, numeroSecreto=50, acertou=0, numeroTentativas=0, pontos=1000;

	printf("*************************\n");
	printf("***Jogo de Adivinhação***\n");
	printf("*************************\n\n");
	
	while(!acertou || pontos<=0){
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
		
		/*if(acertou && numeroTentativas==0){
			printf("\nParabéns!\nVocê acertou de primeira!!!\n");
			break;
		}*/
		
		if(acertou){
				printf("\nAcerto Mizeravi!\n");
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
	printf("Você terminou com %i pontos\n",pontos);
	printf("Fim de jogo!\n");
}
