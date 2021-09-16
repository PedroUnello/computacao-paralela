#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>

#define chaveA 17894

//Reaproveitando código da entrega lab4

/*

Neste programa foi utiliza fork para criar 3 processos diferentes que, um de cada vez, ira iterar sobre os elementos dos arrays e, conforme dado no exercício, 
dar um array resultante da multiplicação de dois outros arrays.

Assim a implementação, como comentado abaixo, cria um segmento de memória compartilhado com 9 espaços para inteiro, aonde:
-O primeiro espaço, no indice 0, é equivalente ao indice do vetor que será multiplicado por aquele processo.
-Os ademais de 1 a 3 são os elementos de A.
-Os elementos de 4 a 6 são os elementos de B.
-E os espaços de 7 a 9 são o resultado armazenado.
-Cada processo novo, multiplica o elemento de A pelo elemento de B, mostra no terminal seu PID e o valor novo, em C, 
e incrementa o indice do vetor para que seu processo pai venha de iterar.

Assim como dito no op1_fork.c, que utiliza de uma estratégia muito similar, pode-se dispor a estratégia como ineficiente, 
já que a iteração por um indice compartilhado requer que os processos sigam uma
hierarquia de execucao, tal que só sera garantira pelo wait(); Logo, a definição de adversos processos não propõe pleno paralelismo, 
mesmo que venha de reger SIMD.

*/

int main(){

    int idMemArray;  //Id do segmento para o array
    int * memArray;  //Endereço do segmento acoplado para o array
    int tamanhoArray = 4 * 9; //Espaço de alocamento da memoria compartilhada, (tamanho de int) * (n de elementos)
    
    char *caminho = "/";

    //Cria(pai)/Pega(filho) o id do segmento de memoria compartilhado
    if ( (idMemArray = shmget(ftok(caminho, chaveA), tamanhoArray, IPC_CREAT|IPC_EXCL|0640)) == -1 ){
        perror("Falha ao criar Array");
        exit(1);
    }
    //Recebe um endereço, no contexto de memoria do programa, para o segmento
    memArray = shmat(idMemArray, 0, 0);
    if ( memArray == (int*)-1 ){
        perror("Falha ao acoplar");
        exit(1);
    }
    
    //Valor Inicial (todos os elementos do array)
    *memArray = 1; //Indice inicial do 1 elem
    //Primeiro vetor -> A
    *(memArray + 1) = 5;
    *(memArray + 2) = 12;
    *(memArray + 3) = 2;
    //Segundo Vetor -> B
    *(memArray + 4) = 4;
    *(memArray + 5) = 8;
    *(memArray + 6) = 6;
    
    //Cria e espera o filho
    int i = 0;
    for (i; i < 2; i++){ //A contagem de processos criados no loop é dada por 2^i - 1, assim tendo, no caso atual, 3 processos
        pid_t pid;
        pid = fork();
        wait(NULL);
        if (pid == 0)
        {
            //*(memArray + indiceAtual (no espaço 0) + 7 (indice para C/resposta))
            //Multiplica  *(memArray + indiceAtual (no espaço 0)) -> A
            //por *(memArray + indiceAtual (no espaço 0) + 3 (indice para B))
            *(memArray + (*memArray) + 7) = *(memArray + (*memArray)) * *(memArray + (*memArray) + 3);
            printf("Processo-%d:", getpid());
            printf("%d\n",*(memArray + (*memArray) + 7));
            printf("Indice Atual = %d\n\n", *memArray - 1);
            *memArray = *memArray + 1;
        }

    }
    return 0;
}