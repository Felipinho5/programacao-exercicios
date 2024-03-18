#include <iostream>
#define MAX 250

int main()
{
	char vet[MAX];
	int i;
	FILE *texto;
	texto = fopen("Texto.txt", "r");
	
	for(i = 0; fscanf(texto, "%c", &vet[i]) != EOF; i++);
	
	for(i = 0; i < MAX; i++)
		if(vet[i] == 'a')
			vet[i] = 'A';
	
	texto = fopen("Texto.txt", "w+");
	fprintf(texto, "%s", vet);
	fclose(texto);
	
	return 0;
}
