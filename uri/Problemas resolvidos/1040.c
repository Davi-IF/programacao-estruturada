#include <stdio.h>

int main(){
	double n1, n2, n3, n4, nExame, media, mediaExame;
	
	scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
	
	media = ((n1*2.0)+(n2*3.0)+(n3*4.0)+(n4*1))/10;
	printf("Media: %.1lf\n", media);
	
	if(media>=7.0){
		printf("Aluno aprovado.\n");
	}else if(media>=5.0){
		printf("Aluno em exame.\n");
		scanf("%lf", &nExame);
		printf("Nota do exame: %.1lf\n", nExame);
		mediaExame = (media+nExame)/2;
		if(mediaExame>=5.0){
			printf("Aluno aprovado.\n");
			printf("Media final: %.1lf\n", mediaExame);
		}else{
			printf("Aluno reprovado.\n");
			printf("Media final: %.1lf\n", mediaExame);
		}
	}else{
		printf("Aluno reprovado.\n");
	}
	return  0;
}
