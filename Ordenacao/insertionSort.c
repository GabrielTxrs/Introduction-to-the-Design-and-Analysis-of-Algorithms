/*ALGORITHM InsertionSort(A[0..n - 1])
//Sorts a given array by insertion sort
//Input: An array A[0..n - 1] of n orderable elements
//Output: Array A[0..n - 1] sorted in nondecreasing order
for i = 1 to n - 1 do
    v = A[i]
    j = i - 1
    while j = 0 and A[j ] > v do
        A[j + 1] = A[j ]
        j = j - 1
    A[j + 1] = v
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

/*
89| 45 68 90 29 34 17
45 89| 68 90 29 34 17
45 68 89| 90 29 34 17
45 68 89 90| 29 34 17
29 34 45 68 89 90| 17
17 29 34 45 68 89 90|
*/
int insertionSort2(int tamanho, int *vetor)
{
	int comparacoes;
	int temp;
	int j;
	for(int i = 0; i < tamanho ;i++)
	{
		j = i-1;
		while((j >= 0) && (vetor[j] > vetor[j+1]))
		{
			comparacoes++;
			temp = vetor[j];
			vetor[j] = vetor[j+1];
			vetor[j+1] = temp;
			j = j-1;
		}
	}
	return comparacoes;
}

int insertionSort(int tamanho, int *vetor)
{
	int comparacoes = 0;
	int v;
	int j;
	
	for(int i = 0; i < tamanho ;i++)
	{
		v = vetor[i];
		j = i-1;
		while((j >= 0) &&(vetor[j] > v))
		{
			comparacoes++;
			vetor[j+1] = vetor[j];
			j = j - 1;
		}
		vetor[j+1] = v;
	}
	return comparacoes;
}
   
int main()
{
	int vetor[10];
	
	vetor[0] = 89;
	vetor[1] = 45;
	vetor[2] = 68;
	vetor[3] = 90;
	vetor[4] = 29;
	vetor[5] = 34;
	vetor[6] = 17;

	int tamanhoVetor = 7;
	
	printf("Comparacoes: %d \n",insertionSort(tamanhoVetor, vetor));
	for(int i = 0 ; i < 7 ;i++)
	{
		printf("%d ", vetor[i]);
	}
	//0.02118
	//0,16s
	
	int vetor2[10];
	
	vetor2[0] = 89;
	vetor2[1] = 45;
	vetor2[2] = 68;
	vetor2[3] = 90;
	vetor2[4] = 29;
	vetor2[5] = 34;
	vetor2[6] = 17;

	printf("Comparacoes: %d \n",insertionSort2(tamanhoVetor, vetor2));
	//0.02208
	//0,14s
	//0.02129


	printf("\n");
	for(int i = 0 ; i < 7 ;i++)
	{
		printf("%d ", vetor2[i]);
	}
	return 0;
}
