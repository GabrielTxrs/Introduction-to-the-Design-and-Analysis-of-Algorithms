#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void swap(int* a, int* b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
int lomutoPartition(int inicio, int fim, int *vetor)
{
	int temp;

	int pivot = vetor[inicio];
	int mediana = inicio;// indice do ultimo elemento do primeiro segmento
	for(int i = inicio + 1; i < fim; i++)
	{
		if(vetor[i] < pivot)
		{
			mediana++;
			swap(&vetor[mediana],&vetor[i]);
		}
	}
	swap(&vetor[inicio],&vetor[mediana]);

	return mediana;
}

int main()
{
	int vetor[50];
	
	vetor[0] = 8; // 3
	vetor[1] = 1; // 1
	vetor[2] = 10;// 7
	vetor[3] = 4; // 5
	vetor[4] = 7; // 4
	vetor[5] = 12;// 8
	vetor[6] = 9; // 6
	vetor[7] = 2; // 2
	vetor[8] = 15;// 9

	int tamanhoVetor = 9;
	
	for(int i = 0 ; i < 9 ;i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("\n%d \n",lomutoPartition(0,9,vetor));
	
	for(int i = 0 ; i < 9 ;i++)
	{
		printf("%d ", vetor[i]);
	}
}
