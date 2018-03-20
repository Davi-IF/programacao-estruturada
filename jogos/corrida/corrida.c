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
	printf("	    \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("	    \xBA Bem Vindo! \xBA\n");
	printf("	    \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	printf("A grande corrida da Tartaruga e da Lebre\n\n");
}

void apostaCorrida(){
	printf("Quem voce acha que vai ganhar???\n");
	printf("1) Lebre 2) Tartaruga\n");
	scanf("%d", &aposta);
}

void contagem(){

	system("cls");
	system("color 04");
	printf("       \xDB\xDB\xDB\xDB\xDB\xDB\xDB		\xDB\xDB\xDB\xDB\xDB\xDB\xDB		\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	printf("          \xDB		   \xDB		   \xDB\n");
	printf("          \xDB		   \xDB		   \xDB\n");
	printf("          \xDB		   \xDB		   \xDB\n");
	printf("          \xDB		   \xDB		   \xDB\n");
	printf("          \xDB		   \xDB		   \xDB\n");
	printf("       \xDB\xDB\xDB\xDB\xDB\xDB\xDB		\xDB\xDB\xDB\xDB\xDB\xDB\xDB		\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	//Ascii art = I I I
	for(int i = 0; i<100000000; i++){
		//loop para ganhar tempo na transição entre os desenhos
	}
	system("cls");
	system("color 06");
	printf("       		\xDB\xDB\xDB\xDB\xDB\xDB\xDB		\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	printf("          	   \xDB		   \xDB\n");
	printf("          	   \xDB		   \xDB\n");
	printf("          	   \xDB		   \xDB\n");
	printf("          	   \xDB		   \xDB\n");
	printf("          	   \xDB		   \xDB\n");
	printf("       		\xDB\xDB\xDB\xDB\xDB\xDB\xDB		\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	//Ascii art = I I 
	for(int i = 0; i<100000000; i++){
		
	}
	system("cls");
	system("color 0A");
	printf("       			\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	printf("          		   \xDB\n");
	printf("          		   \xDB\n");
	printf("          		   \xDB\n");
	printf("          		   \xDB\n");
	printf("          		   \xDB\n");
	printf("       			\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
	//Ascii art = I
	for(int i = 0; i<100000000; i++){
		
	}
	system("cls");

	printf("       \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB	\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	printf("       \xDB       \xDB	\xDB      \xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	printf("       \xDB       \xDB	\xDB      \xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	printf("       \xDB		\xDB      \xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	printf("       \xDB		\xDB      \xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	printf("       \xDB    \xDB\xDB\xDB\xDB	\xDB      \xDB	\n");
	printf("       \xDB       \xDB	\xDB      \xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	printf("       \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB	\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB	\xDB\xDB	\xDB\xDB	\xDB\xDB\n");
	//Ascii art = GO!!!
	for(int i = 0; i<100000000; i++){
		
	}
	system("cls");
	system("color 07");
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
				//,/%%\\P <-- Tartaruga
				printf(",/%%\\P");
			}else if(i == lebre){
				//o( )Y> <-- Lebre
				printf("o( )Y>");
			}else if(tartaruga == lebre){
				//Caso ambos estejam na mesma posição
				printf("Lebre diz: ""Saii daqui disgraca!!!""\n");
				lebre++;
			}else{
				printf("_");
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
	if(ganhouTar(tartaruga)){
		printf("A tartaruga venceu!\n");
	}else{
		printf("A Lebre venceu!\n");
	}
}

void verificaAposta(){
	if(ganhouTar(tartaruga) && aposta == 2){
		printf("Uhoool! Voce apostou no azarao e venceu\n");
		printf("Parabens!!!\n");
	}else if(ganhouLeb(lebre) && aposta == 1){
		printf("Parabens! Voce acertou\n");
	}else{
		printf("Xiii... tu nao ganhou a aposta\n");
		printf("Que pena.\n");
	}
}

int main(){

	abertura();
	apostaCorrida();
	contagem();
	corrida();
	ganhou();
	verificaAposta();

	return 0;
}