#include <stdio.h>

/*
* Pedro Unello Neto
* 41929713
* 3. Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9). 
Este número deve ser sempre ímpar.
*/

int main() {
    
	int n = 0;
	
	while (n % 2 == 0)
	{
		printf("\nNumero maximo\n:");
		scanf("%i", &n);
	}
	
	/* Vertical
	int i = 1;
	for (i; i < (n/2) + 2; i++){
		int j = 0;
		for (j; j < i; j++){
			printf("%d", i);
		}
		printf("\n");
	}

	for (i; i < n + 1; i++){
		int k = 0;
		for (k; k < n - i + 1; k++){
			printf("%d", i);
		}
		printf("\n");
	}
	*/

	//Horizontal

	int i = 0;
	for (i; i < n; i++){
		int j = 0;
		for (j; j < i; j++){
			printf(" ");
		}
		for (j; j < n - i; j++){
			printf("%d", j);
		}
		printf("\n");
	}
	
	//
	
    return 0;
}
  
  