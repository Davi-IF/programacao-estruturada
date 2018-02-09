#include <stdio.h>

int main(){
	
	double renda;
	double newRenda, x, y , z;
	scanf("%lf", &renda);
	
	newRenda = renda - 2000;
	
	if(newRenda<=1000){
		printf("Isento\n");
	}else if(newRenda<=2000){
		x = newRenda - 1000;
		newRenda *= 0.08;
		x *= 0.18;
		printf("%.2lf | %.2lf | %.2lf",newRenda, x ,newRenda+x);
	}else if(newRenda<=3500){
		x = newRenda - 1000;
		newRenda *= 0.08;
		x *= 0.18;
		printf("%.2lf | %.2lf | %.2lf",newRenda, x ,newRenda+x);
	}else{
		x = newRenda - 1000;
		newRenda *= 0.18;
		x *= 0.28;
		printf("%.2lf", renda);	
	}
	
	return 0;
}
