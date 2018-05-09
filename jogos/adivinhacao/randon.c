#include <stdio.h>


int main(){
	
	int  n1 = rand();
	printf("%d\n", n1);
	int  n2 = rand();
	printf("%d\n", n2);	
	
	int segundos = time(NULL);
	srand(segundos);
		
	int n3 = rand();
	printf("%d\n", n3);
	
	return 0;
}
