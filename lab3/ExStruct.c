#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Nome: Pedro Unello Neto
  TIA: 41929713
*/

typedef struct{
  char nome[100];
  int idade;
  float altura;
}Pessoa;

//leNomeArquivoEntrada(char * S1);
void LerNomeArq(char * nome)
{
  printf("Nome do Arquivo\n: ");
  scanf("%s", nome);
}

//leDadosUmaPessoa(PESSOA P)
int LerDados(Pessoa * p, FILE * arq)
{
  if (!feof(arq))
  {
    char l[100];
    fgets(l,sizeof(l),arq);
    strcpy(p->nome, l);
    fgets(l,sizeof(l),arq);
    p->idade = atoi(l);
    fgets(l,sizeof(l),arq);
    p->altura = atof(l);
    return 1;
  }
  return 0;
}

int Comp (const void * a, const void * b)
{
  Pessoa *pA = (Pessoa *) a;
  Pessoa *pB = (Pessoa *) b;
  return pA->altura > pB->altura ? -1:1;
}

//fechaArquivo(FILE * Arq)
void FechaArquivo(FILE * arq)
{
  fclose(arq);
}

//ordenaVetor(PESSOA * Povo, int i)
void OrdenaVetor(Pessoa * povo, int i)
{
  qsort( povo, i, sizeof(Pessoa), Comp);
}

//imprimeVetor(PESSOA * Povo, int i)
void ImprimeVetor(Pessoa * povo, int i)
{
  int j = 0;
  for (j; j < i; j++){
    printf("\n%s\n%d\n%f\n",
    povo[j].nome,
    povo[j].idade,
    povo[j].altura
    );
  }
}

int main(void) {
  
  char s1[50];
  Pessoa povo[10], p;
  FILE *arq;
  int i = 0;

  //leNomeArquivoEntrada(S1);
  printf("Nome do Arquivo\n: ");
  scanf("%s", s1);

  //if (abreArquivoAEntrada(Arq, S1) == 1){}
  arq = fopen(s1, "r");
  if (arq != NULL){
    //do {} while (1);
    while (1){
      //if (leDadosUmaPessoa(P)== 1){}
      if (LerDados(&p, arq))
      {
        povo[i] = p;
        i++;
      }
      //else break;
      else { break; }
    }
    
    //fechaArquivo(Arq);
    FechaArquivo(arq);
    //ordenaVetor(Povo, i);
    OrdenaVetor(povo, i);
    //imprimeVetor(Povo,i);
    ImprimeVetor(povo, i);
  
  }

  //else printf("Erro na abertura do arquivo");
  else { printf("Erro na abertura do arquivo"); }
  
  return 0;
}
