#include <stdio.h>
#define TAM 5

int soma(int v[], int n)
{
	if(n == 0)
		return v[0];
		
	else
		return v[n] + soma(v, n-1);
}

int main()
{
	int vet[TAM] = {50, 3, 4, 10, 3};
	int total = soma(vet, TAM-1);
	printf("Soma: %d", total);
	
	return 0;
}
