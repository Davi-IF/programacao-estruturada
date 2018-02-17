#include <stdio.h>
#include <string.h>

//abertura do jogo
void abertura(){
	printf("#=======================#\n");
	printf("#=====Jogo da Forca=====#\n");
	printf("#=======================#\n");
}

//Função de chute, existe a entrada de uma letra 
//adiciona a letra no vetor, correspondente a tentativa 
//utilizando ponteiro
void chute(char chutesDados[], int* numeroTentativa){
	char chute;
		
	printf("\nQual letra? ");
	scanf(" %c", &chute);
	chutesDados[*numeroTentativa] = chute;
	(*numeroTentativa)++;
}
//Função que verifica a letra chutada, e vê se ela corresponde
//a palavra do vetor
//vetor == ponteiro;
int jachutou(char letra, char* chutesDados, int numeroTentativa){
	int achou = 0;
	for(int y=0; y < numeroTentativa; y++){
		if(chutesDados[y] == letra){
			achou = 1;
			break;
		}
	}
	return achou;
}

int main(){
	
	abertura();

	char palavraSecreta[20];
	char chutesDados[26];
	int ganhou = 0;
	int enforcou = 0;
	int numeroTentativa = 0;
	
	sprintf(palavraSecreta, "MELANCIA");

	do{

		for(int x = 0; x < strlen(palavraSecreta); x++){
					
			char letra = palavraSecreta[x];

			if(jachutou(letra, chutesDados, numeroTentativa)){
				printf("%c ", palavraSecreta[x]);
			}else{
				printf("_ ");
			}
		}
		
		chute(chutesDados, &numeroTentativa);

	}while(!ganhou && !enforcou);
		
	return 0;
}
