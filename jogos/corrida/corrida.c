#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tartaruga = 1;
int lebre = 1;
int aposta = 0; 
int chegada = 70;

int movimentoTar[] = {3,3,3,3,3,-6,-6,1,1,1};
int movimentoLeb[] = {0,0,9,9,-12,1,1,1,-2,-2};

void abertura(){
	printf("		***********\n");
	printf("		*Bem vindo*\n");
	printf("		***********\n");
	printf("A grande corrida da Tartaruga e da Lebre\n\n");
}

void apostaCorrida(){
	printf("Quem voce acha que vai ganhar???\n");
	printf("1) Lebre 2) Tartaruga\n");
	scanf("%d", &aposta);
}

int ganhouTar(int tartaruga){
	if(tartaruga>=chegada){
		return 1;
	}else{
		return 0;
	}
}

int ganhouLeb(int lebre){
	if(lebre>=chegada){
		return 1;
	}else{
		return 0;
	}
}

void corrida(){
	int semente = time(NULL);
	srand(semente);
	while(tartaruga<70 && lebre<70){
		for(int i = 0; i<71; i++){
			if(i == tartaruga){
				printf(",(_)P ");
			}else if(i == lebre){
				printf("o( )Y> ");
			}else{
				printf(" ", );
			}
		}
		printf("\n");

		int movTar = rand()%10;
		int movLeb = rand()%10;
		tartaruga += movimentoTar[movTar];
		lebre += movimentoLeb[movLeb];
		if(tartaruga < 1){
			tartaruga = 1;
		}
		if(lebre < 1){
			lebre = 1;
		}
	}
}

void ganhou(){
	if(ganhouTar(int tartaruga)){
		printf("A tartaruga venceu!\n");
	}else{
		printf("A Lebre venceu!\n");
	}
}

void verificaAposta(){
	if(ganhouTar(int tartaruga) && aposta == 2){
		printf("Uhoool! Voce apostou no azarao e venceu\n");
		printf("Parabéns!!!\n");
	}else if(ganhouLeb(int lebre) && aposta == 1){
		printf("Parabéns! Voce acertou\n");
	}else{
		printf("Xiii... tu não ganhou a aposta\n");
		printf("Que pena.\n");
	}
}


int main(){

	abertura();
	apostaCorrida();
	corrida();
	ganhou();
	verificaAposta();

	return 0;
}