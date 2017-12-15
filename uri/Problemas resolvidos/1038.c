#include <stdio.h>

int main(){
	
	int codigo, quant;
	double total;
	
	scanf("%d %d", &codigo, &quant);
	
	switch(codigo){
		case 1 :
			total = 4.00 * quant;
			printf("Total: R$ %.2lf\n", total);
		break;
		case 2 :
			total = 4.50 * quant;
			printf("Total: R$ %.2lf\n", total);
		break;
		case 3 :
			total = 5.00 * quant;
			printf("Total: R$ %.2lf\n", total);
		break;
		case 4 :
			total = 2.00 * quant;
			printf("Total: R$ %.2lf\n", total);
		break;
		case 5 :
			total = 1.50 * quant;
			printf("Total: R$ %.2lf\n", total);
		break;
		
		default :
			printf("Valor Invalido\n");
	}
	
	
	return 0;
}
