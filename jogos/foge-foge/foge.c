#include <stdio.h>
#include <stdlib.h>
#include "foge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

void encontramapa(MAPA* m, POSICAO* p, char c){
	
	for(int i = 0; i < m->linhas; i++){
		for(int j = 0; j < m->colunas; j++){
			if(m->matriz[i][j] == c){
				p->x = i;
				p->y = j;
				return;
			}
		}
	}

}

void move(char comando){

	if (ehdirecao(comando)){
		return;
	}

	switch(comando){
		case 'w':
			m.matriz[heroi.x-1][heroi.y] = '@';
			heroi.x--;
			break;
		case 's':
			m.matriz[heroi.x+1][heroi.y] = '@';
			heroi.x++;
			break;
		case 'a':
			m.matriz[heroi.x][heroi.y-1] = '@';
			heroi.y--;
			break; 
		case 'd':
			m.matriz[heroi.x][heroi.y+1] = '@';
			heroi.y++;
			break;
	}

	m.matriz[x][y] = '.';
}

int ehdirecao(char comando){
	return comando != 'a' && comando != 'w' && comando != 's' && comando != 'd';
}

int ehvalida(MAPA* m, int x, int y){
	if(x>= m->linhas){
		return 0;
	}
	if (y>= m->colunas){
		return 0;
	}
	return 1;
}

int ehvazia(MAPA* m, int x, int y){
	return m->matriz[x][y] == '.';
}

int acabou(){
	return 0;
}

int main(){

	lerMapa(&m);
	encontramapa(&m, &heroi, '@');


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