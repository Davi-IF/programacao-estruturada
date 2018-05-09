#include <stdio.h>
#include <string.h>

int main(){
	
	int valor;
	int n[10];

	scanf("%d", &valor);
	
	int i = 0; 
	for(i; i<10; i++){
		n[i] = valor;
		printf("N[%d] = %d\n",i, n[i]);
		valor*=2;
	}

}