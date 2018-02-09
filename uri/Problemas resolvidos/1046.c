#include <stdio.h>
#include <math.h>
int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);
	if(b<=a){
		b+=24;
		
		printf("O JOGO DUROU %d HORA(S)\n", b-a);
	}else{
		printf("O JOGO DUROU %d HORA(S)\n", abs(a-b));
	}
	
	return 0;
}
