#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"


void lerMapa(MAPA* m){

	FILE* f;
	f = fopen("mapa.txt", "r");

	if(f == 0){	
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	} 

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

	alocaMapa(m);

	//leitura
	for(int i = 0; i < m->linhas; i++){
		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f);

}

void alocaMapa(MAPA* m){

	m->matriz = malloc(sizeof(char*) * m->linhas);

	for(int i = 0; i<m->linhas; i++){
		m->matriz[i] = malloc(sizeof(char) * m->colunas+1); 
	}	
}

void imprimeMapa(MAPA* m){
	for(int i = 0; i < m->linhas; i++){
			printf("%s\n", m->matriz[i]);
	}
}