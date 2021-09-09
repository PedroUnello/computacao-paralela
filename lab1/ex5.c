#include <stdio.h>

/*
* Pedro Unello Neto
* 41929713
* 5. Crie um programa  capaz de multiplicar uma linha de uma matriz de inteiros por um dado número. 
Faça o mesmo para uma coluna. A matriz deve ser lida de teclado
*/

void ImprimeMatriz(int ** mat, int tam){
    int j = 0;
    printf("\nMatriz %dx%d\n", tam, tam);
	for (j; j < tam; j ++){
	    int i = 0;
		for (i; i < tam; i++){
		    printf("%d ", * ( *(mat + j) + i));
		}
	    printf("\n");
	}
}

int main() {
    //Lê o tamanho e matriz
	int tam = 4;
	
	printf("Tamanho NxN\n:");
    scanf("%d", &tam);
	
	int ** matriz = malloc(tam * sizeof(int*));
	int j = 0;
	for (j; j < tam; j ++){
		int i = 0;
		*(matriz + j) = malloc (tam * sizeof(int));
		for (i; i < tam; i++){
		    int elem = 0;
		    printf("\nElemento %dx%d\n:", j, i);
		    scanf("%d", &elem);
			* ( *(matriz + j) + i) = elem;
		}
	}
	
	ImprimeMatriz(matriz, tam);
	
	//Lê o n a multiplicar
	int n = 1;
	printf("Multiplicar por\n:");
	scanf("%d", &n);
	
	//Multiplica 1 linha e 1 coluna
	
	int k = 0;
	for (k; k < tam; k++){
		* ( *(matriz + k)) = * ( *(matriz + k)) * n;
	}
	
	int l = 0;
	for (l; l < tam; l++){
		* ( *(matriz + 0) + l) = * ( *(matriz + 0) + l) * n;
	}
	
	ImprimeMatriz(matriz,tam);
	
    return 0;
}
  
  