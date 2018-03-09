#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CHEGADA 70
int posL = 1;
int movL[] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};

int posT = 1;
int movT[] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
   
// corrida dos animais     
int corrida (){ 

printf("BANG!!!!\nELES PARTIRAM!!!!\n");
    srand ( time(NULL) );
    while (posL<CHEGADA && posT<CHEGADA) {
        if (posL == posT) 
        
        // QUANDO A TARTARUGA SE ENCONTRA NO MESMO QUADRADO DA LEBRE AI ELA MORDE A LEBRE 
		printf("AI!!!");  
        else {
        	int i;
            for( i=0; i<CHEGADA; i++) {
                if (i == posL) 
				printf("L");
                if (i == posT) 
				printf("T");
                else printf(" "); 
            }
        }
        printf("\n");
        int randL = rand()%10;
        int randT = rand()%10;
        posL += movL[randL];
        posT += movT[randT];
        if (posL < 1) posL = 1;
        if (posT < 1) posT = 1;
    }
}

//VERIFICA QUEM FOI QUE CHEGOU 
int chegada (){ 
	
	if (posL>=CHEGADA) {
        if (posT>=CHEGADA) {
            printf("EMPATE!!!\n");
        }
        else printf("LEBRE VENCE\n");
    }
    else printf("TARTARUGA VENCE!!! E ISSO AI!!!\n");
}
int main(void){
    
    
    corrida();
    chegada();
    
}