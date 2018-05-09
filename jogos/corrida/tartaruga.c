#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ganhouTar(int tartaruga){
	if(tartaruga>=10){
		return 1;
	}else{
		return 0;
	}
}

void verificaTar(int* movimentoTar, int* tartaruga){
	if(*movimentoTar == 0){
		printf("A tartaruga avancou 3 casas\n");
		(*tartaruga) += 2;
	}else if(*movimentoTar == 1){
		printf("A tartaruga escorregou 6 casa\n");
		(*tartaruga) -= 6;
	}else{
		printf("A tartaruga avancou 1  casa\n");
		(*tartaruga)++;
	}
}

void desenhaTar(int tartaruga){
	for(int i = 0; i<tartaruga; i++){
			printf(",(_)P ");
	}
	printf("\n");
}

int ganhouLeb(int lebre){
	if(lebre>=10){
		return 1;
	}else{
		return 0;
	}
}

void verificaLeb(int *movimentoLeb, int* lebre){
	if(*movimentoLeb == 0){
		printf("A lebre dormiu! Zzz...\n");
	}else if(*movimentoLeb == 1){
		printf("A lebre avancou 9 casas\n");
		(*lebre) += 9;
	}else if(*movimentoLeb == 2){
		printf("A lebre escorregou 12 casas\n");
		(*lebre) -= 12;
	}else if(*movimentoLeb == 3){
		printf("A lebre avancou 1 casa\n");
		(*lebre) ++;
	}else{
		printf("A lebre escorregou 2 casas\n");
		(*lebre) -= 2;
	}
}

void desenhaLeb(int lebre){
	for(int i = 0; i<lebre; i++){
			printf("o( )Y> ");
	}
	printf("\n");
}

int main(){
	
	int tartaruga = 0;
	int lebre = 0;

	int semente = time(NULL);
	srand(semente);

	while(!ganhouTar(tartaruga) && !ganhouLeb(lebre)){
		int movimentoTar = rand() % 3;
		int movimentoLeb = rand() % 5;

		verificaTar(&movimentoTar, &tartaruga);
		//desenhaTar(tartaruga);
		verificaLeb(&movimentoLeb, &lebre);
		//desenhaLeb(lebre);
		//system("pause");
		printf("\n");
	}
	
	printf("Tartaruga = %d\n", tartaruga);
	printf("Lebre = %d\n", lebre);
	if(ganhouTar(tartaruga)){
		printf("A tartaruga venceu\n");
	}else{
		printf("A Lebre venceu\n");
	}

}