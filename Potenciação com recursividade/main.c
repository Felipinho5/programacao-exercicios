#include <stdio.h>

int potencia(int base, int expoente)
{	
	if(expoente == 0) return 1;
	
	else return base * potencia(base, expoente-1);
}

int main()
{
	int base;
	int expoente;
	
	printf("Insira uma base inteira: ");
	scanf("%d", &base);
	printf("Insira um expoente inteiro positivo: ");
	scanf("%d", &expoente);
	
	printf("Resultado: %d", potencia(base, expoente));
	
	return 0;
}
