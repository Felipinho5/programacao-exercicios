#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arqEnt = fopen("arqEntrada.txt", "r");
    FILE *arqSai = fopen("arqSaida.txt", "w+");
    char cidade[50];
    int linha = 1, i;

    for(i = 0; fscanf(arqEnt, "%c", &cidade[i]) != EOF; i++)
    {
        if(cidade[i] == '\n')
        {
            cidade[i+1] = '\0';
            fprintf(arqSai, "%d: %s", linha, cidade);

            i = -1;
            linha++;
        }
    }

    cidade[i] = '\0';
    fprintf(arqSai, "%d: %s", linha, cidade);

    return 0;
}
