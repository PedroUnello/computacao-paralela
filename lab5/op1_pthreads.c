#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*

Neste programa foi utilizada as POSIX threads para criar 8 threads diferentes que irão iterar sobre os elementos do array e, conforme dado no exercício, 
multiplicar o elemento atual por um n dado pelo usuario.

Assim a implementação, como comentado abaixo, cria 8 threads que utilizarão uma função definida para multiplicar um elemento por N.

Em discrepância a vista com fork, acredito que é passível atrelar essa implementação, já que a iteração por diferentes threads é de fácil implementação pelo
programador, como tal rege uso de multi-core e trabalha eficiêntemente sobre as instruções nos dados do vetor, além de serem menores que outros processos, serem
mais facilmente criadas e destruidas e engendrarem paralelismo real com sobreposição de tarefas.

obs: a ordenação na hora de imprimir os valores, em vezes, está errada, como tal foram encontrados erros de valores não apresentados (quando n > 2)
*/

int n; //Valor para multiplicar

void * MultiplicaElem(void * thr)
{
    int *v = (int*)thr; //Recebe o elemento atual
    printf("Valor Antes: %d\n",*(v)); //Printa o valor antigo
    *v = *v * n; //Multiplica por n
    printf("Valor Depois: %d\n\n",*(v)); //Printa o novo
}

int main(){
    //Recebe o n
    printf("N para multiplar o array = ");
    scanf("%d",&n);
    //Aloca o vetor
    int * v = malloc(sizeof(int) * 8);
    *(v) = 10;
    *(v + 1) = 32;
    *(v + 2) = 43;
    *(v + 3) = 5;
    *(v + 4) = 12;
    *(v + 5) = 22;
    *(v + 6) = 3;
    *(v + 7) = 9;
    //Cria as threads e passa o valor no indice i do vetor v para a thread
    pthread_t id;
    int i = 0;
    for (i; i < 8; i++){
        pthread_create(&id, NULL, MultiplicaElem, (void*)&v[i]);
    }

    return 0;
}