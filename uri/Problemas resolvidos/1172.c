#include <stdio.h>

int main(){
	
	int x[10];
	int tam = sizeof(x)/sizeof(int);

	int i = 0;
	for(i; i<tam; i++){
		scanf("%d", &x[i]);
	}

	int j = 0;
	for(j; j<tam; j++){
		if(x[j]<=0){
			x[j] = 1;
		}

		printf("X[%d] = %d\n", j, x[j]);
	}
}