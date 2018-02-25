#include<stdio.h>

int main(){
	
	int n[1000];
	int tam;
	int t;

	tam = sizeof(n)/sizeof(int);

	scanf("%d", &t);

	int j = t;
	int i = 0;
	for(i; i<tam; i++){	
		if(j>0){
			n[i] = t - j;
			j--;
		}
		if(j == 0){
			j = t;
		}
	}

	int k = 0;
	for(k; k<tam; k++){
		printf("N[%d] = %d\n", k, n[k]);
	}

}