#include <stdio.h>
#include <string.h>
int main(){
	
	char palavraSecreta[20];
	char chutesDados[26];
	int ganhou = 0;
	int enforcou = 0;
	int numeroTentativa = 0;
	
	sprintf(palavraSecreta, "MELANCIA");

	printf("ç");
	
	do{
		int x;
		for(x = 0; x < strlen(palavraSecreta); x++){
			
			int achou = 0;
			
			int y;
			for(y=0; y < numeroTentativa; y++){
				if(chutesDados[y] == palavraSecreta[x]){
					achou = 1;
					break;
				}
			}
			if(achou == 1){
				printf("%c ", palavraSecreta[x]);
			}else{
				printf("_ ");
			}
		}
		
		char chute;
		
		printf("\nQual letra? ");
		scanf(" %c", &chute);
		chutesDados[numeroTentativa] = chute;
		numeroTentativa++;
		
		int i;
		for(i = 0; i<strlen(palavraSecreta); i++){
			if(chute != palavraSecreta[i]){
				
			}
		}
		
	}while(!ganhou && !enforcou);
		
	return 0;
}
