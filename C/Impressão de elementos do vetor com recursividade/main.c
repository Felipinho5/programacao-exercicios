#include <stdio.h>
#define TAM 5

void imprimirVet(int v[], int n)
{
	if(n == TAM-1)
		printf(" %d", v[TAM-1]);
		
	else
	{
		printf(" %d", v[n]);
		imprimirVet(v, n+1);
	}
}

int main()
{
	int vet[TAM] = {50, 40, 30, 20, 10};
	printf("Vetor:");
	imprimirVet(vet, 0);
	
	return 0;
}
