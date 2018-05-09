#include <stdio.h>

int main(){
	
	double n;
	int notas;
	
	
	scanf("%lf", &n);
	n *= 100;
	notas = (int)n;
	n -=notas;
	
	//576.73
	
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", notas/10000);
	notas %=10000;
	printf("%d nota(s) de R$ 50.00\n", notas/5000);
	notas %=5000;
	printf("%d nota(s) de R$ 20.00\n", notas/2000);
	notas %=2000;
	printf("%d nota(s) de R$ 10.00\n", notas/1000);
	notas %=1000;
	printf("%d nota(s) de R$ 5.00\n", notas/500);
	notas %=500;
	printf("%d nota(s) de R$ 2.00\n", notas/200);
	notas %=200;
	
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", notas/100);
	notas %=100;
	printf("%d moeda(s) de R$ 0.50\n", notas/50);
	notas %=50;
	printf("%d moeda(s) de R$ 0.25\n", notas/25);
	notas %=25;
	printf("%d moeda(s) de R$ 0.10\n", notas/10);
	notas %=10;
	printf("%d moeda(s) de R$ 0.05\n", notas/5);
	notas %=5;
	printf("%d moeda(s) de R$ 0.01\n", notas);
	
	return 0;
}
