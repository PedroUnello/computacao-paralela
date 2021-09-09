#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>

#define chave 41929713

/*
Pedro Unello Neto
41929713
*/

int main(){

    int idMem;  //Id do segmento
    int * mem;  //Endereço do segmento acoplado
    int tamanho = 4;    //Tamanho para uso de um inteiro no segmento (int 2 - 4)
    char *caminho = "/";
    
    //Cria(pai)/Pega(filho) o id do segmento de memoria compartilhado
    if ( (idMem = shmget(ftok(caminho, chave), tamanho, IPC_CREAT|IPC_EXCL|0640)) == -1 ){
        perror("Falha ao criar");
        exit(1);
    }
    //Recebe um endereço, no contexto de memoria do programa, para o segmento
    mem = shmat(idMem, 0, 0);
    if ( mem == (int*)-1 ){
        perror("Falha ao acoplar");
        exit(1);
    }
    
    //Valor Inicial
    *mem = 1;
    
    //Printa o valor inicial
    printf("%d:", getpid());
    printf("%d\n",*mem);
    //Cria e espera o filho
    pid_t pid;
    pid = fork();
    wait(NULL);
    //Para o filho
    if (pid == 0){
        //Acresce de 2 e imprime o novo valor, ademais a PID do programa
        *mem = *mem + 2;
        printf("%d:", getpid());
        printf("%d\n",*mem);

    }
    //Para o pai
    else{
        //Multiplica por 4 o valor compartilhado ademais a imprimir tal resultado
        *mem = *mem * 4;
        printf("%d:", getpid());
        printf("%d\n",*mem);

    }

    return 0;
}