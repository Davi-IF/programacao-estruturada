#include <stdio.h>
#include <stdlib.h>
#include "foge.h"
#include "mapa.h"

MAPA m;

void move(char comando){
	int x,y;

	for(int i = 0; i < m.linhas; i++){
		for(int j = 0; j < m.colunas; j++){
			if(m.matriz[i][j] == '@'){
				x = i;
				y = j;
				break;
			}
		}
	}

	switch(comando){
		case 'w':
			m.matriz[x-1][y] = '@';
			break;
		case 's':
			m.matriz[x+1][y] = '@';
			break;
		case 'a':
			m.matriz[x][y-1] = '@';
			break; 
		case 'd':
			m.matriz[x][y+1] = '@';
			break;
	}
	m.matriz[x][y] = '.';
}

int acabou(){
	return 0;
}

int main(){

	lerMapa(&m);

	do{
		char comando;
		system("cls");
		imprimeMapa(&m);
		//le entrada
		scanf(" %c", &comando);

		move(comando);

		//atualizar mapa
	}while(!acabou());

	return 0;
}