#include <stdio.h>
#include <string.h>

/*
* Pedro Unello Neto
* 41929713
* 14. Faça uma rotina que insira um caracter em uma string do tipo char Str[100], dada a posição do caracter.
*/


void InsereChar(char * s, int pos, char * p){
    int i = strlen(s);
    if (pos > i){
        *(s+i) = p[0];
    }
    else{
        for (i; i > pos; i--){
            *(s+i) = *(s + i - 1);
        }
        *(s+pos) = p[0];
    }
}

int main() {
    
    char teste[100] = "Essa string possui um easkter egg em easter egg";
    printf("\nInserindo O na posicao 30:");
    InsereChar(teste, 30, "O");
    printf("\n%s\n", teste);
    
    printf("\nInserindo K na posicao 60:");
    InsereChar(teste, 60, "K");
    printf("\n%s\n", teste);

    
}
  
  