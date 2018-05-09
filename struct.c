#include <stdio.h>
#include <stdlib.h>
#define QTD_ALUNOS 3

struct aluno{
	char nome[20];
	int matricula;
	double media, n1, n2;
};

typedef struct aluno A;

int main(int argc, char const *argv[]){
		
	A alunos[QTD_ALUNOS];

	system("clear");
	for (int i = 0; i < QTD_ALUNOS; ++i){
		printf("Digite o nome do aluno:\n");
		scanf("%s", alunos[i].nome);
		printf("Digite sua matricula:\n");
		scanf("%d", &alunos[i].matricula);
		printf("Digite a N1 e N2 do aluno:\n");
		scanf("%lf %lf", &alunos[i].n1, &alunos[i].n2);

		alunos[i].media = (alunos[i].n1 + alunos[i].n2)/2;

		system("clear");
	}

	for (int j = 0; j < QTD_ALUNOS; ++j){
		printf("******************************\n");
		printf("Aluno: %s\n", alunos[j].nome);
		printf("Media: %.1lf\n", alunos[j].media);
		printf("******************************\n");

	}

	return 0;
}