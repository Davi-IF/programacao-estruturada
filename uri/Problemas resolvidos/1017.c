#include <stdio.h>

int main(){
	
	int horas, kmHoras;
	float litros;
	
	scanf("%d", &horas);
	scanf("%d", &kmHoras);
	
	litros = (float)(kmHoras * horas)/12;
	
	printf("%.3f\n", litros);
	
	return 0;
}
