#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>


/*

Neste programa foi utilizado AVX intrinsics para iterar sobre os elementos do array paralelamente e, conforme dado no exercício,
multiplicar um array a por um array b, dando o resultado em c

Assim a implementação, como comentado abaixo, utiliza da immintrin.h e impõe instruções vetoriais nos vetores de 256 bits,
a estruturação do programa é muito similar ao op1_simd.c, tido a semelhança dos exercícios, aqui apenas diferindo de utilizar
dois vetores de 256bits

Como dito no op1_simd.c, a implementação é simples, contemplando grande abstração no uso do paralelismo SIMD, apenas engendrando problemas
no uso referido na linguagem C, a qual diferente do uso em C++, compõe grandes chances de emergirem problemas

obs:
Para compilar esse código foi utilizado o comando: 
    gcc -march=haswell -mavx op2_simd.c
E para executar tal, foi utilizado
    ./a.out

*/


int main(){
    //Cria o vetor de floats de 256bits, referente ao A do exercício
    __m256 a = _mm256_set_ps(15.0, 9.0, 6.0, 53.0, 8.0, 7.0, 45.0, 2.0);
    //Cria o vetor de floats de 256bits, referente ao B do exercício
    __m256 b = _mm256_set_ps(16.0, 90.0, 8.0, 4.0, 2.0, 10.0, 78.0, 1.0);
    //Multiplica, indice a indice, os valores nos vetores A e B, dando o resultado em C
    __m256 c = _mm256_mul_ps(a, b);
    float resultado[8]; //Cria um vetor de resultados
    //Armazena os elementos do vetor de 256 bits no vetor de resultados
    _mm256_storeu_ps(resultado, c); 
    //Imprime os valores multiplicados (porem, nao sei porque, esta invertido, colocando os finais no começo... )
    int i = 0;
    for (i; i < 8; i++){
        printf("Valor: %f\n", resultado[i]);
    }

    return 0;
}