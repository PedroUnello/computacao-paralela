#include <stdio.h>
#include <stdlib.h>

/*
* Pedro Unello Neto
* 41929713
* 11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. 
O resultado deve ser colocado na linha L2. 
Faça o mesmo com a multiplicação.
*/

void Soma(int ** mat, int tamUm, int tamDois){
    int atual = 0;
    while (atual < tamUm && atual < tamDois){
        int um = *(*(mat + 0) + atual);
        int dois = *(*(mat + 1) + atual);
        *( *(mat + 1) + atual) =  um + dois;
        printf("elem um = %d\n elem dois = %d\n resultado = %d\n\n", 
        um, dois, *( *(mat + 1) + atual)
        );
        atual++;
    }
}

void Multi(int ** mat,  int tamUm, int tamDois){
    int atual = 0;
    while (atual < tamUm && atual < tamDois){
        int um = *(*(mat + 0) + atual);
        int dois = *(*(mat + 1) + atual);
        *( *(mat + 1) + atual) =  um * dois;
        printf("elem um = %d\n elem dois = %d\n resultado = %d\n\n", 
        um, dois, *( *(mat + 1) + atual)
        );
        atual++;
    }
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
	printf("Soma\n\n");
	//Soma
	Soma(matriz, tam, tam);
    printf("Multi\n\n");
    //Multiplicao utilizando matriz já com soma feita
    Multi(matriz, tam, tam);
    
    return 0;
}