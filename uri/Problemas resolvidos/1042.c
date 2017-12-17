#include <stdio.h>
#include <math.h>

int main(){
	
	int n1, n2, n3, maiorAB, maiorABC, menorABC, medioABC;
	
	scanf("%d %d %d", &n1, &n2, &n3);
	
	if(n1<=n2 && n1<=n3){
		menorABC = n1;
	}else if(n2<=n1 && n2<=n3){
		menorABC = n2;
	}else if(n3<=n1 && n3<=n2){
		menorABC = n3;
	}
	maiorAB = (n1+n2+abs(n1-n2))/2;
	maiorABC = (maiorAB + n3+abs(maiorAB-n3))/2;
	
	/*
	if(n1!=menorABC && n1!=maiorABC){
		medioABC = n1;
	}else if(n2!=menorABC && n2!=maiorABC){
		medioABC = n2;
	}else{
		medioABC = n3;
	}*/
	
	if(n1==maiorABC && n2==menorABC){
		medioABC = n3;
	}else if(n2==maiorABC && n3==menorABC){
		medioABC = n1;
	}else{
		medioABC = n2;
	}
	
	printf("%d\n",menorABC);
	printf("%d\n", medioABC);
	printf("%d\n\n", maiorABC);
	
	printf("%d\n%d\n%d\n", n1, n2, n3);
	
	return 0;
}
