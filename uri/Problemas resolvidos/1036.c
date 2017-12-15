#include <stdio.h>
#include <math.h>
int main(){
	
	double a, b, c, delta, r1, r2;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	delta = pow(b,2) - 4*a*c;
	r1 = (-b +sqrt(delta))/(2*a);
	r2 = (-b -sqrt(delta))/(2*a);
	if(a!=0 && delta>0){
		printf("R1 = %.5lf\n", r1);
		printf("R2 = %.5lf\n", r2);
	}else{
		printf("Impossivel calcular");
		
	}
	
	return 0;
}
