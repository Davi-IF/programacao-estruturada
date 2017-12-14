#include <stdio.h>

int main(){
	
	int numero, quantHoras;
	double valorFinal, valorHora;
	
	scanf("%d", &numero);
	scanf("%d", &quantHoras);
	scanf("%lf", &valorHora);
	
	valorFinal = quantHoras * valorHora;
	
	printf("NUMBER = %d\n", numero);
	printf("SALARY = U$ %.2lf\n", valorFinal);
	
	return 0;
}
