#include <stdio.h>
#include <stdlib.h>

int main(){

	int colunas = 10;
	int linhas = 5;

	int** matriz;

	matriz = malloc(sizeof(int*) * linhas);

	for (int i = 0; i < linhas; i++){
		matriz[i] = malloc(sizeof(int) * colunas);
	}

	matriz[2][3] = 10;

	printf("%d\n", matriz[2][3]);



	return 0;
}