#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
    Pedro Unello Neto
        41929713
*/

#include <math.h>
#define pot 6

int thread_count; //passado na chamada

double sum = 0; //Soma para pi
int n = pow(10,pot); //n = 10^pot

void* Thread_sum(void* rank){ //Função proposta no exercício
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor){
        sum += factor/(2*i+1);
    }

    return NULL;
}

int main(int argc, char* argv[]){
    long thread;
    pthread_t* thread_handles;

    //Pega os argumentos da chamada
    thread_count = strtol(argv[1], NULL, 10); 

    thread_handles = malloc (thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++){
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
    }

    for (thread = 0; thread < thread_count; thread++){
        pthread_join(thread_handles[thread], NULL);
    }

    free(thread_handles);

    //Printao resultado de pi
    printf("\n pi = %f\n", sum * 4);

    return 0;
}
