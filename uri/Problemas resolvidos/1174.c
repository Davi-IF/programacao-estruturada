#include <stdio.h>

int main(){
	
	double a[100];

	int i=0;
	for(i; i<100; i++){
		double x;
		scanf("%lf", &x);

		a[i] = x;
	}
	int j=0;
	for(j; j<100; j++){

		if(a[j]<=10){
			printf("A[%d] = %.1lf\n", j, a[j]);
		}
	}
}