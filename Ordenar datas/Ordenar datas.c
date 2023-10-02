#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct Data
{
    int dia, mes, ano;
} Data;

void ordena(Data v[], int tam);
void troca(Data v[], int i);

int main()
{
    setlocale(LC_ALL, "Portuguese");
   
    Data *vet;
    int qtd;
   
    printf("Número de datas a ordenar: ");
    scanf("%d", &qtd);
    printf("\n");
   
    vet = malloc(qtd * sizeof(Data));
   
    for(int i = 0; i < qtd; i++)
    {
        printf("DATA %d", i+1);
       
        printf("\n");
       
        printf("Dia: ");
        scanf("%d", &vet[i].dia);
       
        printf("Mês: ");
        scanf("%d", &vet[i].mes);
       
        printf("Ano: ");
        scanf("%d", &vet[i].ano);
       
        printf("\n");
    }
   
    ordena(vet, qtd);
   
    printf("DATAS ORDENADAS\n\n");
   
    for(int i = 0; i < qtd; i++)
        printf("%dª - %d/%d/%d\n", i+1, vet[i].dia, vet[i].mes, vet[i].ano);
       
    free(vet);    
       
    return 0;
}

void ordena(Data v[], int tam)
{
    for(int j = 0; j < tam-1; j++)
    {
        for(int i = 0; i < tam-j-1; i++)
        {
            if(v[i].ano > v[i+1].ano)
                troca(v, i);
               
            else if(v[i].ano == v[i+1].ano)
            {
                if(v[i].mes > v[i+1].mes)
                    troca(v, i);
                   
                else if(v[i].mes == v[i+1].mes)
               
                    if(v[i].dia > v[i+1].dia)
                        troca(v, i);
            }
        }
    }
}

void troca(Data v[], int i)
{
    Data aux = v[i];
    v[i] = v[i+1];
    v[i+1] = aux;
}