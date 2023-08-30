#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
/*
ALGORITHM ComparisonCountingSort(A[0..n - 1])
//Sorts an array by comparison counting
//Input: An array A[0..n - 1] of orderable elements
//Output: Array S[0..n - 1] of A’s elements sorted in nondecreasing order
for i ? 0 to n - 1 do Count[i]? 0
for i ? 0 to n - 2 do
for j ? i + 1 to n - 1 do
if A[i] < A[j ]
Count[j ]? Count[j ] + 1
else Count[i]? Count[i] + 1
for i ? 0 to n - 1 do S[Count[i]]? A[i]
return S
*/
void ComparisonCountingSort(int *vetor, int tamanho, int *vetor2) {

	int contador[tamanho*2];
	
	for(int i = 0; i < tamanho; i++) {
		contador[i] = 0;
	}
	for(int i = 0; i < tamanho-1; i++) {
		for(int j = i+1; j < tamanho; j++) {
			if(vetor[i] < vetor[j]) {
				contador[j]++;
			}
			else {
				contador[i]++;
			}
		}
	}
	for(int i = 0; i < tamanho; i++) {
		vetor2[contador[i]] = vetor[i];
	}
}



int main()
{
	int vetor[20];
	
	int vetorOrdenado[20];
	
	
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
	printf("\n");
	
	ComparisonCountingSort(vetor, 10, vetorOrdenado);
	
	for(int i = 0; i < 10 ; i++)
	{
	    printf("%d ", vetorOrdenado[i]);
	}
	
	return 0;
}
