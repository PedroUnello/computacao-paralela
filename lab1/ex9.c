#include <stdio.h>

/*
* Pedro Unello Neto
* 41929713
* 9. Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.
*/

void ImprimeMatriz(int ** mat, int tamI, int tamJ){
    int j = 0;
    printf("\nMatriz %dx%d\n", tamI, tamJ);
	for (j; j < tamI; j ++){
	    int i = 0;
		for (i; i < tamJ; i++){
		    printf("%d ", * ( *(mat + j) + i));
		}
	    printf("\n");
	}
}

int main() {
    
    //Lê o tamanho e matriz
    int tamI = 4;
    int tamJ = 5;
	
	int ** matriz = malloc(tamI * sizeof(int*));
	int i = 0;
	for (i; i < tamI; i ++){
		int j = 0;
		*(matriz + i) = malloc (tamJ * sizeof(int));
		for (j; j < tamJ; j++){
			* ( *(matriz + i) + j) = i - j;
		}
	}
	
	ImprimeMatriz(matriz, tamI, tamJ);
	
    printf("\nModulo\n");
    
	int l = 0;
	for (l; l < tamI; l ++){
	    int k = 0;
		for (k; k < tamJ; k++){
		    if (* ( *(matriz + l) + k) < 0 ){
		        * ( *(matriz + l) + k) = * ( *(matriz + l) + k) * -1;
		    }
		}
	}
	
	ImprimeMatriz(matriz,tamI, tamJ);
	
    return 0;
}
  
  