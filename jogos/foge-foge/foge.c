#include <stdio.h>
#include <stdlib.h>

char** mapa;
int linhas, colunas;

void lerMapa(){
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0){
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	} 

	fscanf(f, "%d %d", &linhas, &colunas);

	alaocaMapa();
	
	//leitura
	for(int i = 0; i<linhas; i++){
		fscanf(f, "%s", mapa[i]);
	}

	fclose(f);
}

void alocaMapa(){
	mapa = malloc(sizeof(char*) * linhas);

	for(int i = 0; i<linhas; i++){
		mapa[i] = malloc(sizeof(char) * colunas+1); 
	}	
}

int main(){
	//impressão

	lerMapa();

	for(int i = 0; i < linhas; i++){
		printf("%s\n", mapa[i]);
	}

	return 0;
}