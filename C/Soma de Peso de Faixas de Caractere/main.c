 #include <stdio.h>
 #define MAX 7

typedef struct Cell
{
	char car;
	int peso;
} Cell;

int somaPesoFaixas(Cell vet[], int tamanho)
{
	int i, soma = 0;
	
	for(i = 0; i < tamanho - 1; i++)
	{
		while(vet[i].car == vet[i+1].car && i < tamanho - 1)
		{
			soma += vet[i].peso;
			i++;
		}
		
		if(vet[i].car == vet[i-1].car && i > 0)
			soma += vet[i].peso;
	}
	
	return soma;
}

int main()
{
	Cell vet[MAX];
	
	vet[0].car = 'y'; vet[0].peso = 10;
	vet[1].car = 'y'; vet[1].peso = 2;
	vet[2].car = 'z'; vet[2].peso = 5;
	vet[3].car = 'z'; vet[3].peso = 4;
	vet[4].car = 'z'; vet[4].peso = 5;
	vet[5].car = 'y'; vet[5].peso = 4;
	vet[6].car = 'a'; vet[6].peso = 3;
	
	printf("Soma do peso das faixas: %d", somaPesoFaixas(vet, MAX));
	
	return 0;
}
