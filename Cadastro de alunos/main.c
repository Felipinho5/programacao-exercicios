#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 3

typedef struct Aluno
{
	char nome[100];
	int RA;
} Aluno;

void imprimeArquivo(char nomeArq[]);
void alteraNome(char nomeArq[], int ra, char nome[]);

int main()
{
	setlocale(LC_ALL, "Portuguese");

	Aluno registro[TAM] =
	{
		{"Fulano", 23001},
		{"Sicrano", 23002},
		{"Beltrano", 23003}
	};

	char nomeArq[50] = "Registro.bin";
	FILE *arq = fopen(nomeArq, "r+b");

	if(arq == NULL)
    {
        fprintf(stderr, "Arquivo inexistente.");
        return 1;
    }

	fwrite(registro, sizeof(Aluno), TAM, arq);
	fclose(arq);

	int escolha;

	do
	{
		puts("1 - Alterar o nome de um aluno");
		puts("2 - Exibir o registro completo");
		puts("3 - Sair do programa");
		printf("Digite uma opção: ");
		scanf(" %d", &escolha);
		fflush(stdin);

		if(escolha == 1)
		{
			int alunoRA;
			printf("\nRA do aluno: ");
			scanf(" %d", &alunoRA);
			fflush(stdin);

			char novoNome[100+1];
			printf("Novo nome do aluno: ");
			fgets(novoNome, 100+1, stdin);

			int tamNome = strlen(novoNome) - 1;
			if(novoNome[tamNome] == '\n') novoNome[tamNome] = '\0';

			alteraNome(nomeArq, alunoRA, novoNome);
		}

		else if(escolha == 2) imprimeArquivo(nomeArq);
		else if(escolha != 3) printf("\nEscolha inválida.\n");
	}
	while(escolha != 3);

	return 0;
}

void imprimeArquivo(char nomeArq[])
{
	FILE *arq = fopen(nomeArq, "r+b");
	Aluno registro[TAM];

	fread(registro, sizeof(Aluno), TAM, arq);

	for(int i = 0; i < TAM; i++)
		printf("\nNome: %s, RA: %d", registro[i].nome, registro[i].RA);

	printf("\n\n");

	fclose(arq);
}

void alteraNome(char nomeArq[], int alunoRA, char novoNome[])
{
	FILE *arq = fopen(nomeArq, "r+b");
	Aluno registro;
	registro.RA = 0;
	int achou = 0;

	fseek(arq, 0, SEEK_SET);

	while(registro.RA != alunoRA && fread(&registro, sizeof(Aluno), 1, arq) != 0)
	{
		if(registro.RA == alunoRA)
		{
			achou = 1;
			fseek(arq, -1 * sizeof(Aluno), SEEK_CUR);
			strcpy(registro.nome, novoNome);
			fwrite(&registro, sizeof(Aluno), 1, arq);
		}
	}

	if(achou == 0) printf("Aluno não encontrado.\n");

	printf("\n");

	fclose(arq);
}
