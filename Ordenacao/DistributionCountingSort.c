#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

/*
//Sorts an array of integers from a limited range by distribution counting
//Input: An array A[0..n - 1] of integers between l and u (l = u)
//Output: Array S[0..n - 1] of A’s elements sorted in nondecreasing order

ALGORITHM DistributionCountingSort(A[0..n - 1], l, u)
for j = 0 to u - l 
    D[j ]? 0 //initialize frequencies
for i = 0 to n - 1 
    D[A[i] - l] = D[A[i] - l] + 1 //compute frequencies
for j = 1 to u - l 
    D[j] = D[j - 1] + D[j ] //reuse for distribution
for i = n - 1 downto 0 do
    j = A[i] - l
    S[D[j ] - 1] = A[i]
    D[j ] = D[j ] - 1
return S
*/
int maior(int *vetor, int tamanho) {
	int maiorValor = 0;
	for(int i = 0; i < tamanho; i++) {
		if(vetor[i] > maiorValor) {
			maiorValor = vetor[i];
		}
	}
	//printf("maiorValor : %d",maiorValor);
	return maiorValor;
}
int menor(int *vetor, int tamanho) {
	int menorValor = INT_MAX;
	
	for(int i = 0; i < tamanho; i++) {
		if(vetor[i] < menorValor) {
			menorValor = vetor[i];
		}
	}
	//printf("menorValor : %d",menorValor);
	return menorValor;
}

void DistributionCountingSort(int *vetor, int tamanho, int *vetorOrdenado) {
	int l = menor(vetor, tamanho);
	int u = maior(vetor, tamanho);
	
	int frequencias[u-l+1];
	
	for(int j = 0; j <= u-l; j++) {     
		frequencias[j] = 0; 
	}// inicializa as frequencias
	for(int i = 0; i < tamanho; i++) { 
		frequencias[vetor[i]-l] = frequencias[vetor[i]-l]+1;
	}// calcula as frequencias
	for(int j = 1; j <= u-l; j++) { 
		frequencias[j] = frequencias[j-1] + frequencias[j];
	}// reusa para a distribuicao
	int j;
	for(int i = tamanho-1; i > -1; i--) {
		j = vetor[i] - l;
        vetorOrdenado[frequencias[j] - 1] = vetor[i];
        frequencias[j] = frequencias[j] - 1;
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
	vetor[5] = 7;
	vetor[6] = 3;
	vetor[7] = 8;
	vetor[8] = 1;
	vetor[9] = 10;

	int tamanhoVetor = 10;
	
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", vetor[i]);
	}
	printf("\n");

	DistributionCountingSort(vetor, 10, vetorOrdenado);
	
	for(int i = 0; i < 10 ; i++)
	{
	    printf("%d ", vetorOrdenado[i]);
	}
	
	return 0;
}
