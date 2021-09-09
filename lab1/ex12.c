#include <stdio.h>
#include <string.h>

/*
* Pedro Unello Neto
* 41929713
* 12. Faça uma função que retorne a posição de um dado caracter dentro de uma string.
*/


int PosicaoChar(char * s, char * p){
    int i = 0;
    int max = strlen(s);
    while (s[i] != p[0]){
        i++;
        if (i > max){
            i = -1;
            break;
        }
    }
    return i;
}

int main() {
    
    char teste[100] = "Essa string possui um easkter egg em easter egg";
    printf("\nProcurando k:");
    printf("\n%d\n", PosicaoChar(teste, "k"));
    printf("\nProcurando z:");
    printf("\n%d\n", PosicaoChar(teste, "z"));
    
}
  
  