#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void busca(int vet[], int tam, int chave, int posicoes[], int *n);

int main()
{
    int *vet, tam, chave, *posicoes, n = 0;
    
    printf("Tam: ");
    scanf("%d", &tam);
    printf("\n");
    
    vet = (int*)malloc(tam*sizeof(int));
    posicoes = (int*)malloc(tam*sizeof(int));
    
    for(int i = 0; i < tam; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &vet[i]);
    }
    
    printf("Chave: ");
    scanf("%d", &chave);
    
    bubbleSort(vet, tam);
    busca(vet, tam, chave, posicoes, &n);
    
    printf("\n");
    printf("Posicoes:");
    
    for(int i = 0; i < n; i++)
        printf(" %d", posicoes[i]);
    
    free(vet);
    return 0;
}

void busca(int vet[], int tam, int chave, int posicoes[], int *n)
{
    int c = tam/2 - 1;
    
    while(tam > 0)
    {
        if(vet[c] == chave)
        {
            for(int i = 1; vet[c-1] == chave; i++)
                c--;
            
            for(int i = 0; vet[c+i] == chave; i++)
            {
                posicoes[i] = c+i;
                (*n)++;
            }
            
            break;
        }
        
        else if(vet[c] > chave) c /= 2;
        else if(vet[c] < chave) c *= 2;
        
        tam /= 2;
    }
}

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to optimize if no swaps are made in a pass

        // Last i elements are already in place, so no need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to 1 to indicate a swap
            }
        }

        // If no two elements were swapped in the inner loop, the array is sorted
        if (!swapped) {
            break;
        }
    }
}