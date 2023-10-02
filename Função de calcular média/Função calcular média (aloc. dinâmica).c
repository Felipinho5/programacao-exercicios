#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double media(double v[], int tam);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    double *vet;
    int tam;
    
    printf("Quantidade de números a serem digitados: ");
    scanf("%d", &tam);
    printf("\n");
    
    vet = malloc(tam * sizeof(double));
    
    for(int i = 0; i < tam; i++)
    {
        printf("Valor do índice %d: ", i);
        scanf("%lf", &vet[i]);
    }
    
    double med;
    med = media(vet, tam);
    
    printf("A média é: %.2lf", med);
    
    free(vet);
    
    return 0;
}

double media(double v[], int tam)
{
    double soma = 0, med;
    
    for(int i = 0; i < tam; i++)
        soma += v[i];
        
    med = soma / tam;
    return med;
}