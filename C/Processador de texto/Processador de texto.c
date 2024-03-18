#include <stdio.h>
#include <string.h>
#define MAX 500+1

int main()
{
    char texto[MAX];
    int i, palavra = 0;
   
    printf("Insira um texto abaixo:\n");
    fgets(texto, MAX, stdin);
    fflush(stdin);
   
    for(i = 0; texto[i] != '\0'; i++)
    {
        if(texto[i] != ' ' && texto[i] != '\n' && texto[i] != '\0' && (texto[i+1] == ' ' || texto[i+1] == '\n' || texto[i+1] == '\0')) palavra++;
    }
   
    printf("\n\nQuantidade de palavras: %d", palavra);
   
    printf("\n\n-----------------------------------------------\n\n");
   
    int j, nChar, achou;
    char busca[MAX];
   
    do
    {
        printf("Palavra para localizar (escreva \"#\" para sair): ");
        fgets(busca, MAX, stdin);
        fflush(stdin);
   
        if(busca[0] == '#' && busca[1] == '\n')
            break;
   
        nChar = strlen(busca);
   
        if(busca[nChar] == '\n')
            nChar -= 1;
   
        printf("\nPOSI%c%cES", 128, 229);
   
        for(i = achou = 0; i < MAX - nChar; i++)
        {
            for(j = 0; texto[i+j] == busca[j] && j < nChar; j++);
   
            if(j == nChar)
            {
                achou = 1;
                printf("\nCaracteres de %cndice %d at%c %d", 161, i, 130, i+j-1);
            }
        }

        if(achou == 0)
            printf("\nNada encontrado");

        printf("\n\n-----------------------------------------------\n\n");
    }
    while(1);
   
    return 0;
}