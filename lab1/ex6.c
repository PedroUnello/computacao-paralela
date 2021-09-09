#include <stdio.h>

/*
* Pedro Unello Neto
* 41929713
* 6. Crie um programa capaz de criar a transposta de uma matriz. A matriz deve ser lida de teclado.
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

int** TranspoeMatriz(int ** mat, int tamI, int tamJ){
    int j = 0;
    int ** matriz = malloc(tamJ * sizeof(int*));
	for (j; j < tamJ; j ++){
	    int i = 0;
	    *(matriz + j) = malloc (tamI * sizeof(int));
		for (i; i < tamI; i++){
		    * ( *(matriz + j) + i) = * ( *(mat + i) + j);
		}
	}
	return matriz;
}

int main() {
    
    //Lê o tamanho e matriz
    int tamI = 0;
    int tamJ = 0;
	printf("Tamanho I\n:");
    scanf("%d", &tamI);
	
	printf("Tamanho J\n:");
    scanf("%d", &tamJ);
	
	int ** matriz = malloc(tamI * sizeof(int*));
	int i = 0;
	for (i; i < tamI; i ++){
		int j = 0;
		*(matriz + i) = malloc (tamJ * sizeof(int));
		for (j; j < tamJ; j++){
		    int elem = 0;
		    printf("\nElemento %dx%d\n:", i, j);
		    scanf("%d", &elem);
			* ( *(matriz + i) + j) = elem;
		}
	}
	
	ImprimeMatriz(matriz, tamI, tamJ);
	
    printf("\nTransposta\n");
	
	matriz = TranspoeMatriz(matriz, tamI, tamJ);
	
	ImprimeMatriz(matriz,tamJ, tamI);
	
    return 0;
}
  
  