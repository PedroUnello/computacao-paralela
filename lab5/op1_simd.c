#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>


/*

Neste programa foi utilizado AVX intrinsics para iterar sobre os elementos do array paralelamente e, conforme dado no exercício, 
multiplicar o elemento atual por um n dado pelo usuario.

Assim a implementação, como comentado abaixo, utiliza da immintrin.h e impõe instruções vetoriais nos vetores de 256 bits

Já esta implementação, empregando o que teve de ser feito, é tida por mim como eficiênte, na disposição do código regido abaixo, é passível que se veja uma certa
facilidade de uso, porém, o uso desta estratégia não ao todo  é facil, tido principalmente a disposição de erros quando não suposta em c++

obs:
Para compilar esse código foi utilizado o comando: 
    gcc -march=haswell -mavx op1_simd.c
E para executar tal, foi utilizado
    ./a.out


*/


int main(){
    //Recebe do usuário o n que ira multiplicar os elementos
    float n;
    printf("N para multiplar o array = ");
    scanf("%f",&n);
    //Cria o vetor de floats de 256bits
    __m256 v = _mm256_set_ps(15.0, 9.0, 6.0, 53.0, 8.0, 7.0, 45.0, 2.0);
    //Cria o vetor de floats de 256bits, so que preenchendo com todas as posicoes tendo o valor de n
    __m256 nA = _mm256_set1_ps(n);
    //Multiplica, indice a indice, os valores nos vetores v e nA
    __m256 rA = _mm256_mul_ps(v, nA);
    float resultado[8]; //Cria um vetor de resultados
    //Armazena os elementos do vetor de 256 bits no vetor de resultados
    _mm256_storeu_ps(resultado, rA); 
    //Imprime os valores multiplicados (porem, nao sei porque, esta invertido, colocando os finais no começo... )
    int i = 0;
    for (i; i < 9; i++){
        printf("Valor: %f", resultado[i]);
    }

    return 0;
}