#include<stdio.h>
#include<stdlib.h>


int main(){
	
	long long fib[61];

	fib[0] = 0;
	fib[1] = 1;

	int i = 2;
	for(i; i<=60; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}

	int t;
	scanf("%d", &t);

	int j = 0;
	for(j; j<t; j++ ){
		int posicao;
		scanf("%d", &posicao);

		printf("Fib[%d] = %lld\n", posicao, fib[posicao]);
	}
}