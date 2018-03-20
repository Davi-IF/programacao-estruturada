#include <stdio.h>
#include <stdlib.h>


int main(){
	
	char** mapa;
	int linhas, colunas;

	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0){
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	} 

	fscanf(f, "%d %d", &linhas, &colunas);

	//alocação
	mapa = malloc(sizeof(char*) * linhas);

	for(int i = 0; i<linhas; i++){
		mapa[i] = malloc(sizeof(char) * colunas+1); 
	}

	//leitura

	for(int i = 0; i<linhas; i++){
		fscanf(f, "%s", mapa[i]);
	}

	fclose(f);

	//impressão

	for(int i = 0; i < linhas; i++){
		printf("%s\n", mapa[i]);
	}


	return 0;
}