#include <stdio.h>
#include <string.h>
/*
* Pedro Unello Neto
* 41929713
* 3. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++
*/

int main() {

	char nomeum[100];
	char nomedois[100];

	printf("\nPrimeiro Nome\n: ");
	gets(nomeum);
	printf("\nSegundo nome\n: ");	
	gets(nomedois);
	
	int maior = 0;
	int i = 0;
	
	while (maior == 0){
	    
        if (nomeum[i] > 'z'){
            nomeum[i] = nomeum[i] - 32;
        }
        if (nomedois[i] > 'z'){
            nomedois[i] = nomedois[i] - 32;
        }
        
        if (nomeum[i] > nomedois[i]){
            maior = 1;
        }
        else if (nomeum[i] < nomedois[i]){
            maior = 2;
        }
        
        i++;
	}
	
	if (maior == 2){
	    printf("\n%s\n", nomeum);
	    printf("%s\n", nomedois);
	}
	else{
	    printf("\n%s\n", nomedois);
	    printf("%s\n", nomeum);
	}
	
    return 0;
}
  
  