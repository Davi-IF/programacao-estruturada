#include <stdio.h>

int main(){
	
	double salario, salarioFinal;
	
	scanf("%lf", &salario);
	
	if(salario<=400){
		salarioFinal = salario + (salario*0.15);
		printf("Novo salario: %.2lf\n", salarioFinal);
		printf("Reajuste ganho: %.2lf\n", salario*0.15);
		printf("Em percentual: 15 %%\n");
		
	}else if(salario>400 && salario <= 800){
		salarioFinal = salario + (salario*0.12);
		printf("Novo salario: %.2lf\n", salarioFinal);
		printf("Reajuste ganho: %.2lf\n", salario*0.12);
		printf("Em percentual: 12 %%\n");
		
	}else if(salario>800 && salario <= 1200){
		salarioFinal = salario + (salario*0.10);
		printf("Novo salario: %.2lf\n", salarioFinal);
		printf("Reajuste ganho: %.2lf\n", salario*0.10);
		printf("Em percentual: 10 %%\n");
	}else if(salario>1200 && salario <=2000){
		salarioFinal = salario + (salario*0.07);
		printf("Novo salario: %.2lf\n", salarioFinal);
		printf("Reajuste ganho: %.2lf\n", salario*0.07);
		printf("Em percentual: 7 %%\n");
	}else if(salario>2000){
		salarioFinal = salario + (salario*0.04);
		printf("Novo salario: %.2lf\n", salarioFinal);
		printf("Reajuste ganho: %.2lf\n", salario*0.04);
		printf("Em percentual: 4 %%\n");
	}
	
	return 0;
}
