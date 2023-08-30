#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int bubbleSort(int tamanhodalista, int *vetordeinteiros)
{
	int comparacoes = 0;
	int temporario; // variavel para guardar o valor durante a troca
	for(int i = 0; i < tamanhodalista-1; i++)
	{
		for(int j = 0; j < (tamanhodalista-1)-i; j++)
		{
			if(vetordeinteiros[j+1] < vetordeinteiros[j])
			{
				temporario = vetordeinteiros[j];
				vetordeinteiros[j] = vetordeinteiros[j+1];
				vetordeinteiros[j+1] = temporario;
				contador++;
			}
		}
	}
	return comparacoes;
}

int main()
{
	int vetor[100];
	
	vetor[0] = 5;
	vetor[1] = 50;
	vetor[2] = 25;
	vetor[3] = 20;
	vetor[4] = 10;
	vetor[5] = 6;
	vetor[6] = 45;
	vetor[7] = 43;
	vetor[8] = 37;
	vetor[9] = 28;
	
	int tamanhoVetor = 10;
	
	printf("Comparacoes: %d \n",bubbleSort(tamanhoVetor, vetor));
	
	for(int i = 0 ; i < 10 ;i++)
	{
		printf("%d ",vetor[i]);
	}
	
}

