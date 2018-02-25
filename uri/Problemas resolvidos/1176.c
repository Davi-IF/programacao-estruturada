#include <stdio.h>

int main(){
	
	unsigned long long int fib[61];
	int tenta;

	fib[0] = 0;
	fib[1] = 1;

	int i = 2;
	for(i; i<61; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}

	scanf("%d", &tenta);
	int resul[tenta];

	int j = 0;
	for(j; j<tenta; j++){
		int entrada;
		scanf("%d", &entrada);
		resul[j] = entrada;
	}
	int k = 0;
	for(k; k<tenta; k++){
		printf("Fib(%d) = %llu\n",resul[k], fib[resul[k]] );
	}

}