#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*

Neste programa foi utilizada as POSIX threads para criar 3 threads diferentes que irão iterar sobre os elementos dos arrays A e B e, conforme dado no exercício, 
multiplicar os elementos de A e B para dar em C (apenas impressão).

Assim a implementação, como comentado abaixo, cria 3 threads que utilizarão uma função definida para multiplicar um elemento por outro.

Assim como dito no op1_pthreads.c, é eficiente a estratégia apresentada aqui, tido que a única depreensão de algo não tão eficiênte, é composto na 
implementação

obs: a implementação foi funcional apenas em compilar, tido que não apresenta resultado ao executar
*/

int n; //Valor para multiplicar
int a[3] = {3,5,7};
int b[3] = {1,4,9};


void * MultiplicaElem(void * thr)
{
    int *i = (int*)thr; //Recebe o indice atual
    printf("Valor em A: %d\n",a[*i]); //Printa o valor em A
    printf("Valor em B: %d\n",b[*i]); //Printa o valor em B
    printf("Valor A x B: %d\n\n", (a[*i]) *  (b[*i]) ); //Printa o novo valor/multiplicação a * b
}

int main(){

    //Cria as threads e passa o indice i para a thread
    pthread_t id;
    int i = 0;
    for (i; i < 3; i++){
        pthread_create(&id, NULL, MultiplicaElem, (void*)&i);
    }

    return 0;
}