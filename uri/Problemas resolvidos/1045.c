#include <stdio.h>
#include <math.h>
int main(){
	
	double n1, n2, n3, maiorAB, maiorABC, menorABC, medioABC;
	
	scanf("%lf %lf %lf", &n1, &n2, &n3);
	
	 if (n1 < n2){
        n1 = n1 + n2;
        n2 = n1 - n2;
        n1 = n1 - n2;
    }
	if (n1 < n3){
        n1 = n1 + n3;
        n3 = n1 - n3;
        n1 = n1 - n3;
    }
    if (n2< n3){
        n2  = n2 + n3;
        n3 = n2 - n3;
        n2 = n2 - n3;
    }
	
	maiorABC = n1;
	medioABC = n2;
	menorABC = n3;
	
	if(maiorABC>=medioABC+menorABC){
		printf("NAO FORMA TRIANGULO\n");
	}else if(pow(maiorABC,2)==pow(medioABC,2)+pow(menorABC,2)){
		printf("TRIANGULO RETANGULO\n");
	}else if(pow(maiorABC,2)>pow(medioABC,2)+pow(menorABC,2)){
		printf("TRIANGULO OBTUSANGULO\n");
	}else if(pow(maiorABC,2)<pow(medioABC,2)+pow(menorABC,2)){
		printf("TRIANGULO ACUTANGULO\n");
	}
	
	if(n1==n2 && n2==n3){
		printf("TRIANGULO EQUILATERO\n");
	}else if(n1==n2 || n2==n3 || n1 == n3){
		printf("TRIANGULO ISOSCELES\n");
	}
	return 0;
}
