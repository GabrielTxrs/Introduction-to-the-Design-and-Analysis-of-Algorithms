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

int lomutoPartition(int inicio, int fim, int *vetor)
{
	int pivot = vetor[inicio];
	int mediana = inicio;// indice do ultimo elemento do primeiro segmento
	for(int i = inicio + 1; i < fim; i++)
	{
		if(vetor[i] < pivot)
		{
			mediana++;
			trocar(&vetor[mediana],&vetor[i]);
		}
	}
	trocar(&vetor[inicio],&vetor[mediana]);
	return mediana;
}
/*
ALGORITHM Quicksort(A[l..r])
//Sorts a subarray by quicksort
//Input: Subarray of array A[0..n - 1], defined by its left and right
// indices l and r
//Output: Subarray A[l..r] sorted in nondecreasing order
if l < r
   s = Partition(A[l..r]) //s is a split position
   Quicksort(A[l..s - 1])
   Quicksort(A[s + 1..r])
*/
int QuickSort(int inicio, int fim, int *vetor)
{
	int particao;
	if(inicio < fim)
	{
		particao = lomutoPartition(inicio, fim, vetor);
		QuickSort(inicio, fim-1, vetor);
		QuickSort(inicio+1, fim, vetor);
	}
}

int main()
{
	int vetor[20];
	
	vetor[0] = 4;
	vetor[1] = 5;
	vetor[2] = 6;
	vetor[3] = 9;
	vetor[4] = 2;
	vetor[5] = 3;
	vetor[6] = 1;
	vetor[7] = 8;
	vetor[8] = 7;
	vetor[9] = 10;

	int tamanhoVetor = 9;
	
	for(int i = 0 ; i < 9 ;i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("\n");
	printf("contador = %d ",QuickSort(0, tamanhoVetor, vetor));
	printf("\n");
	for(int i = 0 ; i < 9 ;i++)
	{
		printf("%d ", vetor[i]);
	}
}
