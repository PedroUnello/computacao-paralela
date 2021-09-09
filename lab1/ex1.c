#include <stdio.h>
#include <stdlib.h>

/*
* Pedro Unello Neto
* 41929713
* 1. Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros. 
Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.
*/

int MenorInteiro(int ** mat, int tam) {
	int menor = 0;
	int j = 0;
	for (j; j < tam; j ++){
		int i = 0;
		for (i; i < tam; i++){
			if (*( *(mat + j) + i) < menor)
			{
				menor = j;
			}
		}
	}
	return menor;
}

int main() {
	//Exemplo de matriz
	int tam = 4;
	int ** matriz = malloc(tam * sizeof(int*));
	int j = 0;
	for (j; j < tam; j ++){
		int i = 0;
		*(matriz + j) = malloc (tam * sizeof(int));
		for (i; i < tam; i++){
			* ( *(matriz + j) + i) = i + j;
		}
	}
	//Resultado
	int res = MenorInteiro(matriz, tam);
    printf("Linha = %d", res);
    return 0;
}