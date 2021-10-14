#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define tam 6; //Tamanho da matriz

int n = tam; 
int m = tam; 
int thread_count = 3;

int A[ 6 ][ 6 ] = { //M ixj para i = j

        {6,4,2,5,3,1},
        {1,6,4,2,5,3},
        {3,1,6,4,2,5},
        {5,3,1,6,4,2},
        {2,5,3,1,6,4},
        {4,2,5,3,1,6}

    }; //Exemplo dado: sequência de pares e impares 
       //de 1 a 6 deslocando 1 posição a direita por linha (v circular)

int x[6] = {4,1,9,2,9,7};
float y[6]; //y = matriz A * vetor X

void *Pth_mat_vect( void* rank ) { //Função dada no exercício.
    long my_rank = (long) rank;
    int i, j;
    int local_m = m/thread_count;
    int my_first_row = my_rank*local_m;
    int my_last_row = (my_rank+1)*local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++)
            y[i] += A[i][j]*x[j];
    }

    return NULL;
}   /* Pth_mat_vect */

int main(){

    long thread;
    pthread_t *thread_handles = malloc (thread_count * sizeof(pthread_t));
    
    for (thread = 0; thread < thread_count; thread++){
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }
    for (thread = 0; thread < thread_count; thread++){
        pthread_join(thread_handles[thread], NULL);
    }

    free(thread_handles);

    printf("y = { %f , %f , %f , %f , %f , %f }\n", 
            y[0],y[1],y[2],y[3],y[4],y[5]);

    return 0;
}