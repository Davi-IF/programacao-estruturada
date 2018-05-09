#include <stdio.h>

int main(){
	
	double valor;
	double n[100];

	scanf("%lf", &valor);
	
	int i = 0; 
	for(i; i<100; i++){
		n[i] = valor;
		printf("N[%d] = %.4lf\n",i, n[i]);
		valor/=2;
	}

}