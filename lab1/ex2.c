#include <stdio.h>

/*
* Pedro Unello Neto
* 41929713
* 2. Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. 
Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. 
A partir da média, informar o conceito de acordo com a tabela:
[Era pra ter uma tabela aqui]
*/

int main() {

	int i = 0;
	float num = 0;
	float ndois = 0;
	float ntres = 0;
	float me = 0;
	while (i != 6){
		printf("\n\n1- Alterar N1\n 2- Alterar N2\n 3- Alterar N3\n 4- Alterar M.E.\n 5- Calcular media\n 6- Sair\n: ");
		scanf("%i", &i);
		float nota = 0;
		switch(i){
			case 1:
				printf("\nN1 igual a: ");
				scanf("%f", &nota);
				if (nota >= 0 && nota <= 10){
					num = nota;
					printf("N1 igual a %f", nota);
					break;
				}
				printf("%f nao e uma nota valida", nota);
				break;
			case 2:
				printf("\nN2 igual a: ");
				scanf("%f", &nota);
				if (nota >= 0 && nota <= 10){
					ndois = nota;
					printf("N2 igual a %f", nota);
					break;
				}
				printf("%f nao e uma nota valida", nota);
				break;
			case 3:
				printf("\nN3 igual a: ");
				scanf("%f", &nota);
				if (nota >= 0 && nota <= 10){
					ntres = nota;
					printf("N3 igual a %f", nota);
					break;
				}
				printf("%f nao e uma nota valida", nota);
				break;
			case 4:
				printf("\nM.E. igual a: ");
				scanf("%f", &nota);
				if (nota >= 0 && nota <= 10){
					me = nota;
					printf("M.E. igual a %f", nota);
					break;
				}
				printf("%f nao e uma nota valida", nota);
				break;
			case 5:
				{
					float media = (num + ndois*2 + ntres*3 + me)/7;
					printf("%f - ", media);
					if (media >= 9){
						printf("A");
					}
					else if (media >= 7.5){
						printf("B");
					}
					else if (media >= 6){
						printf("C");
					}
					else if (media >= 4){
						printf("D");
					}
					else{
						printf("E");
					}
					break;
				}
		}
	}
	
    return 0;
}
  