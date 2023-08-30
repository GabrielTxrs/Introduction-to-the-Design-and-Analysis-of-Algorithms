#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>


void trocar(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int HoarePartition(int inicio, int fim, int *vetor)
{
	int pivot = vetor[inicio];
	int i = inicio;
	int j = fim;
	do
	{
		do{ i++; }while(!(vetor[i] >= pivot));
		
		do{ j--; }while(!(vetor[j] <= pivot));
		
		trocar(&vetor[i], &vetor[j]);
	}while(!(i >= j));
	
	trocar(&vetor[i], &vetor[j]);
	trocar(&vetor[inicio], &vetor[j]);
	
	return j;
}
void QuickSort(int inicio, int fim, int *vetor)
{
	int particao;
	if(inicio < fim)
	{
		particao = HoarePartition(inicio, fim, vetor);
		QuickSort(inicio, fim-1, vetor);
		QuickSort(inicio+1, fim, vetor);
	}
}
int main()
{
	int vetor[30];
	
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
	
	for(int i = 0 ; i < 10 ;i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("\n");
	
	//printf("\nHoare = %d ", HoarePartition(0, 10, vetor));
	QuickSort(0, 10, vetor);
	printf("\n");
	for(int i = 0 ; i < 10 ;i++)
	{
		printf("%d ", vetor[i]);
	}
}
