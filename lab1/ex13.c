#include <stdio.h>
#include <string.h>

/*
* Pedro Unello Neto
* 41929713
* 13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.
*/


void RemoveChar(char * s, int pos){
    int i = strlen(s);
    if (pos < i){
        for (pos; pos < i; pos++){
            *(s + pos) = *(s + pos + 1);
        }
    }
}

int main() {
    
    char teste[100] = "Essa string possui um easkter egg em easter egg";
    
    printf("\nRemovendo o na posicao 13:");
    RemoveChar(teste, 13);
    printf("\n%s\n", teste);
    
    printf("\nRemovendo E na posicao 0:");
    RemoveChar(teste, 0);
    printf("\n%s\n", teste);

    printf("\nRemovendo o 'easter egg' em easter egg:");
    RemoveChar(teste, 23);
    printf("\n%s\n", teste);
}
  
  