#include <stdio.h>
#include <string.h>

/*
* Pedro Unello Neto
* 41929713
* 7. Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct. 
O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas. 
A struct deve armazenar os dados de idade, peso e altura.
*/

typedef struct{
    char * nome; 
    int idade;
    float peso;
    float altura;
} pessoa;

pessoa CriaPessoa(char * n, int i, float pe, float a){
    pessoa p;
    p.nome = n;
    p.idade = i;
    p.peso = pe;
    p.altura = a;
    return p;
}

void ImprimePessoa(pessoa p){
    printf("\nNome:%s\n"
            "Idade:%d\n"
            "Peso:%f\n"
            "Altura:%f\n",
        p.nome,p.idade,p.peso,p.altura);
}

int main() {
    
    pessoa vP[3];
    int i = 0;
    char nomeum[100];
    char nomedois[100];
    char nometres[100];
    int idade;
    float peso;
    float altura;
    
    for (i; i < 3; i++){
        printf("\nNome %d\n:", i + 1); 
        
        if (i == 0){ scanf("%s", &nomeum); }
        else if (i == 1){ scanf("%s", &nomedois); }
        else{ scanf("%s", &nometres); }
        
        printf("Idade %d\n:", i + 1);
        scanf("%d", &idade);
        printf("Peso %d\n:", i + 1);
        scanf("%f", &peso);
        printf("Altura %d\n:", i + 1);
        scanf("%f", &altura);
        
        if (i == 0){ vP[i] = CriaPessoa(nomeum, idade, peso, altura); }
        else if (i == 1){ vP[i] = CriaPessoa(nomedois, idade, peso, altura); }
        else{ vP[i] = CriaPessoa(nometres, idade, peso, altura); }
        
        
    }
    
    ImprimePessoa(vP[0]);
    ImprimePessoa(vP[1]);
    ImprimePessoa(vP[2]);
    
}
  
  