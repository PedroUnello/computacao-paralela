#include <stdio.h>

/*
* Pedro Unello Neto
* 41929713
* 10. Crie uma função capaz de multiplicar uma linha de uma matriz por um dado número. 
Faça o mesmo para uma coluna.
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
	
	int ** matriz = malloc(tam * sizeof(int*));
	int j = 0;
	for (j; j < tam; j ++){
		int i = 0;
		*(matriz + j) = malloc (tam * sizeof(int));
		for (i; i < tam; i++){
		    int elem = 0;
			* ( *(matriz + j) + i) = i + j;
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
  
  