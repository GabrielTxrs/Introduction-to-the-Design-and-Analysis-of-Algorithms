#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
	int chave;
} ITEM;

typedef struct 
{
	ITEM itens[100];
    int tamanho;
} LISTA;

void inicializar(LISTA *l)
{
    l->tamanho = 0;
}

bool inserir(int chave, LISTA *l)
{
    if(l->tamanho == 100) 
    {
    	return false; // lista cheia
	}
    else
    {
    	l->itens[l->tamanho++].chave = chave;
	}
    return true;
}
void exibirLista(LISTA l)
{
    for (int i = 0; i < l.tamanho; i++)
    {
    	printf("%d ", l.itens[i].chave);
	}
}

bool ordenado(LISTA *l)
{
	for(int i = 0; i < l->tamanho-1 ; i++)
	{
		if(l->itens[i].chave > l->itens[i+1].chave)
		{
			return true;
		}
	}
		return false;
}
/*

ALGORITHM Merge(B[0..p - 1], C[0..q - 1], A[0..p + q - 1])
//Merges two sorted arrays into one sorted array
//Input: Arrays B[0..p - 1] and C[0..q - 1] both sorted
//Output: Sorted array A[0..p + q - 1] of the elements of B and C
i = 0; j = 0; k = 0
while i < p and j < q do
    if B[i] = C[j ]
        A[k] = B[i]; i = i + 1
    else A[k] = C[j ]; j = j + 1
    k = k + 1
if i = p
    copy C[j..q - 1] to A[k..p + q - 1]
else 
    copy B[i..p - 1] to A[k..p + q - 1]
   
*/

void intercala(LISTA *l1, LISTA *l2, LISTA *l3)
{
	if(ordenado(l1) || ordenado(l2))
	{
		return;
	}
	else
	{
	    int i = 0;
	    int j = 0;
	    while(i < l1->tamanho && j < l2->tamanho)
	    {
		    if(l1->itens[i].chave < l2->itens[j].chave)
		    {
			    inserir(l1->itens[i].chave, l3);
			    //l3->itens[k] = l1->itens[i];
			    i++;
		    }
		    else
		    {
			    inserir(l2->itens[j].chave, l3);
			    //l3->itens[k] = l2->itens[j];
			    j++;
		    }
	    }
// Se algum dos arrays ainda possuir elementos não inseridos, adiciona ao array resultado
        while (i < l1->tamanho) 
	    {
		    inserir(l1->itens[i].chave, l3);
            i++;
        }
        while (j < l2->tamanho) 
		{
            inserir(l2->itens[j].chave, l3);
            j++;
        }
	}
}
/*
ALGORITHM Mergesort(A[0..n - 1])
//Sorts array A[0..n - 1] by recursive mergesort
//Input: An array A[0..n - 1] of orderable elements
//Output: Array A[0..n - 1] sorted in nondecreasing order
if n > 1
    copy A[0..n/2 - 1] to B[0..n/2 - 1]
    copy A[n/2..n - 1] to C[0..n/2 - 1]
    Mergesort(B[0..n/2 - 1])
    Mergesort(C[0..n/2 - 1])
    Merge(B, C, A) //see below
*/
void mergeSort(LISTA *l)
{		
	LISTA b;
	LISTA c;
	inicializar(&b);
	inicializar(&c);
	
	if(l->tamanho > 1) //l->tamanho == 8 
	{
		// 0 1 2 3 4 5 6 7
		for(int i = 0; i < (l->tamanho/2); i++)
		{
			inserir(l->itens[i].chave, &b);
		}
		for(int j = (l->tamanho/2); j < l->tamanho; j++)
		{
			inserir(l->itens[j].chave, &c);
		}
		
		mergeSort(&b);
		mergeSort(&c);
		inicializar(l);
		intercala(&b,&c,l);
	}
}
int main() 
{ 
    LISTA l1;
    
    inicializar(&l1);

    inserir(8, &l1);
    inserir(3, &l1);
    inserir(2, &l1);
    inserir(9, &l1);
    inserir(7, &l1);
    inserir(1, &l1);
    inserir(5, &l1);
    inserir(4, &l1);
		
	exibirLista(l1);
	printf("\n");
	mergeSort(&l1);
	printf("\n");
	exibirLista(l1);

  return 0; 
}

