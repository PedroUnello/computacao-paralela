#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>

#define chaveA 2459578

//Reaproveitando código da entrega lab4

/*

Neste programa foi utiliza fork para criar 8 processos diferentes que, um de cada vez, ira iterar sobre os elementos do array e, conforme dado no exercício, 
multiplicar o elemento atual por um n dado pelo usuario.

Assim a implementação, como comentado abaixo, cria um segmento de memória compartilhado com 8 espaços para inteiro, aonde:
-O primeiro espaço, no indice 0, é equivalente ao indice do vetor que será multiplicado por aquele processo.
-Os ademais são os elementos a serem multiplicados por n.
-Cada processo novo, multiplica o elemento por n, mostra no terminal seu PID e o valor novo, 
e incrementa o indice do vetor para que seu processo pai venha de iterar.

Esta implementação/estratégia de paralelismo é, ao que acredito, ineficiente, já que a iteração por um indice compartilhado requer que os processos sigam uma
hierarquia de execucao, tal que só sera garantira pelo wait(); Logo, a definição de adversos processos não propõe pleno paralelismo, mesmo que venha de reger SIMD.

*/

int main(){

    int idMemArray;  //Id do segmento para o array
    int * memArray;  //Endereço do segmento acoplado para o array
    int tamanhoArray = 4 * 8; //Espaço de alocamento da memoria compartilhada, (tamanho de int) * (n de elementos)
    
    int n;
    printf("N para multiplar o array = ");
    scanf("%d",&n);

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
    *memArray = 1;
    *(memArray + 1) = 5;
    *(memArray + 2) = 12;
    *(memArray + 3) = 2;
    *(memArray + 4) = 3;
    *(memArray + 5) = 4;
    *(memArray + 6) = 8;
    *(memArray + 7) = 6;
    
    //Cria e espera o filho
    int i = 0;
    for (i; i < 3; i++){ //A contagem de processos criados no loop é dada por 2^i - 1, assim tendo, no caso atual, 7 processos
        pid_t pid;
        pid = fork();
        wait(NULL);
        //Para o filho
        if (pid == 0){
            //*(memArray + indiceAtual (no espaço 0))
            //Multiplica por n e armazena
            *(memArray + (*memArray)) = *(memArray + (*memArray)) * n;
            printf("Processo-%d:", getpid());
            printf("%d\n",*(memArray + (*memArray)));
            *memArray = *memArray + 1;
            printf("Indice Atual = %d\n\n", *memArray);
        }
    }



    return 0;
}