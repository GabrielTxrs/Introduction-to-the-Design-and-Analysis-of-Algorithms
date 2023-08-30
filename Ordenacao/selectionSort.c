#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int SelectionSort(int tamanho, int *vetordeint)
{
	int comparacoes = 0;
	int menor;
	int temp;
	for(int i = 0; i < tamanho-1; i++)
	{
	    menor = i;
		for(int j = i+1; j < tamanho; j++)
		{
			if(vetordeint[j] < vetordeint[menor])
			{
				menor = j;
				comparacoes++;
			}
		}
		temp = vetordeint[i];
		vetordeint[i] = vetordeint[menor];
		vetordeint[menor] = temp;
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
	printf("Comparacoes: %d \n",SelectionSort(tamanhoVetor, vetor));
	
	for(int i = 0 ; i < 10 ;i++)
	{
		printf("%d ",vetor[i]);
	}
	return 0;
}
