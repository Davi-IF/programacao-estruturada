#include <stdio.h>
#include <string.h>

int main(){
	
	char nome1[64], nome2[64], nome3[64];
	
	scanf("%s", &nome1);
	scanf("%s", &nome2);
	scanf("%s", &nome3);
	
	if(nome1 == "vertebrado"){
		if(nome2 == "ave"){
			if(nome3 == "carnivoro"){
				printf("aguia\n");
			}else if(nome3 == "onivoro"){
				printf("pomba\n");
			}
		}else if(nome2 == "mamifero"){
			if(nome3 == "herbivoro"){
				printf("vaca\n");
			}else if(nome3 == "onivoro"){
				printf("onivoro\n");
			}
		}
	}else if(nome1 == "invertebrado"){
		if(nome2 == "inseto"){
			if(nome3 == "hematofago"){
				printf("pulga\n");
			}else if(nome3 == "herbivoro"){
				printf("lagarta\n");
			}
		}else if(nome2 == "analideo"){
			if(nome3 == "hematofago"){
				printf("sanguessuga\n");
			}else if(nome3 == "onivoro"){
				printf("minhoca\n");
			}
		}
	}
	
	return 0;
}
