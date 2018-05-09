#include <stdio.h>

int main(){
	
	int n[20];
	int entrada = 0;

	int i = 0;
	for(i; i<20; i++){
		scanf("%d", &n[i]);
		entrada++;
	}
	int j = 0;
	for(j; j<10; j++){
		int aux;
		aux = n[j];
		n[j] = n[entrada-1];
		n[entrada-1] = aux;
		entrada--; 

	}
	int k = 0;
	for(k; k<20; k++){
		printf("N[%d] = %d\n",k, n[k] );
	}

}