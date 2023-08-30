#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>


void Merge(int tamanhoB, int *vetorB, int tamanhoC, int *vetorC, int tamanhoA, int *vetorA)
{
	int j = 0;
	int i = 0;
	int k = 0;
	while(i < tamanhoB && j < tamanhoC)
	{
		if(vetorB[i] < vetorC[j])
		{
			vetorA[k] = vetorB[i++];
		}
		else
		{
			vetorA[k] = vetorC[j++];
		}
		k++;
	}

	while(i < tamanhoB)
	{
		vetorA[k++] = vetorB[i++];
	}
	while(j < tamanhoC)
	{
		vetorA[k++] = vetorC[j++];
	}
}

void MergeSort(int tamanho, int *vetor)
{
	int b[20];
	int c[20];
	if(tamanho > 1)
	{
		int k = 0;
		for(int i = 0; i < tamanho/2; i++)
		{
			b[k++] = vetor[i];
		}
		int x = 0;
		for(int j = tamanho/2; j < tamanho; j++)
		{
			c[x++] = vetor[j];
		}
		MergeSort(k,b);
		MergeSort(x,c);
		Merge(k, b, x, c, tamanho, vetor);
	}

}


int main()
{
	int vetor[20];
	
	vetor[0] = 5;
	vetor[1] = 4;
	vetor[2] = 6;
	vetor[3] = 9;
	vetor[4] = 2;
	vetor[5] = 3;
	vetor[6] = 1;
	vetor[7] = 8;
	vetor[8] = 7;
	vetor[9] = 10;

	int tamanhoVetor = 10;
	
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", vetor[i]);
	}
	
	MergeSort(10, vetor);
	
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", vetor[i]);
	}
}
