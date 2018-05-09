#include <stdio.h>
#include <string.h>
#include <string.h>

int main(){
	
	char nome1[64], nome2[64], nome3[64];
	
	scanf("%s", &nome1);
	scanf("%s", &nome2);
	scanf("%s", &nome3);
	
	if(strcmp (nome1, "vertebrado") == 0){
		if(strcmp (nome2, "ave") == 0){
			if(strcmp (nome3, "carnivero") == 0){
				printf("aguia\n");
			}else if(strcmp (nome3, "onivoro") == 0){
				printf("pomba\n");
			}
		}else if(strcmp (nome2, "mamifero") == 0){
			if(strcmp (nome3, "herbivoro") == 0){
				printf("vaca\n");
			}else if(strcmp (nome3, "onivoro") == 0){
				printf("onivoro\n");
			}
		}
	}else if(strcmp (nome1, "invertebrado") == 0){
		if(strcmp (nome2, "inseto") == 0){
			if(strcmp (nome3, "hematofago") == 0){
				printf("pulga\n");
			}else if(strcmp (nome3, "herbivoro") == 0){
				printf("lagarta\n");
			}
		}else if(strcmp (nome2, "anelideo") == 0){
			if(strcmp (nome3, "hematofago") == 0){
				printf("sanguessuga\n");
			}else if(strcmp (nome3, "onivoro") == 0){
				printf("minhoca\n");
			}
		}
	}
	
	return 0;
}
