#include <stdio.h>
#include <math.h>

int main(){
	
	int h1, h2, m1, m2, mTotal, hTotal;
	
	scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
	
	
	if(h1==h2 && m1==m2){
		printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
		
	}else if(h2<h1){
		h2+=24;
		
		h1 *= 60;
		h2 *= 60;
		m1 += h1;
		m2 += h2;
			
		mTotal = abs(m1-m2);
			
		hTotal = mTotal/60;
		mTotal %=60;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hTotal, mTotal);
	}else{
		h1 *= 60;
		h2 *= 60;
		m1 += h1;
		m2 += h2;
			
		mTotal = abs(m1-m2);
			
		hTotal = mTotal/60;
		mTotal %=60;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hTotal, mTotal);
	}
	return 0;
}
