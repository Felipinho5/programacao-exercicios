#include <stdio.h>
#include <string.h>
#define MAX 129

// Nome: Felipe de Carvalho Santos (fiz sozinho)
// RA: 2760482311028
/* Este programa recebe dois parâmetros: um arquivo .ppm de entrada e outro de saída. Ele tem o objetivo
de possibilitar que o usuário escolha entre dois efeitos - cinza e esticar contraste - e os aplique no
arquivo de saída, baseando-se no de entrada. Basicamente, ele aplica um filtro à imagem. */

// Struct para facilitar o armazenamento dos RGBs e melhorar a legibilidade
typedef struct Rgb 
{
	int r, g, b;
} Rgb;

// Função para ler a imagem e copiar seus RGBs para a matriz-origem
void lerImagem(char *nome, Rgb m[MAX][MAX], int *colunas, int *linhas)
{
	int i, j, lixo;
	char p;

	FILE *f;
	f = fopen(nome, "r");
	
	// Avisar erro caso o arquivo não for encontrado
	if(f == NULL)
	{
		printf("Erro ao abrir a imagem \"%s\".\n", nome);
		return;
	}
	
	// Encontrar as dimensões da matriz no arquivo e armazená-las
	fscanf(f, "%c", &p);
	fscanf(f, "%d", &lixo);
	fscanf(f, "%d %d", colunas, linhas);
	fscanf(f, "%d", &lixo);
	
	// Ler os RGBs e passá-los para a matriz
	for(i = 0 ; i < (*linhas); i++)
		for(j = 0; j < (*colunas); j++)
			fscanf(f, "%d %d %d", &m[i][j].r, &m[i][j].g, &m[i][j].b);
			
	fclose(f);
}

// Função para escrever o resultado no arquivo de saída
void escreverImagem(char *nome, Rgb m[MAX][MAX], int colunas, int linhas)
{
  	int i, j;
  	
  	FILE *f;
  	f = fopen(nome, "w");
  	
  	// Escrever cabeçalho
  	fprintf(f, "P3\n%d %d\n255\n", colunas, linhas);

	// Escrever matriz-resultado
	for(i = 0; i < linhas ; i++)
	{
		for(j = 0; j < colunas ; j++)
		{
			fprintf(f, "%d %d %d", m[i][j].r, m[i][j].g, m[i][j].b);
			
			if (j < colunas - 1) fprintf(f, " ");
		}
		
		fprintf(f, "\n");
	}
	
	fclose(f);
}

// Função para calcular o efeito "esticar"
void esticarContraste(Rgb m1[MAX][MAX], Rgb m2[MAX][MAX], int colunas, int linhas)
{
	// Definir as intensidades mínima e máxima iniciais
	Rgb min, max;
	min.r = m1[0][0].r; max.r = m1[0][0].r;
	min.g = m1[0][0].g; max.g = m1[0][0].g;
	min.b = m1[0][0].b; max.b = m1[0][0].b;
	
	int i, j;
	
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++)
		{
			// Encontrar as intensidades mínima e máxima definitivas
			if(m1[i][j].r < min.r) min.r = m1[i][j].r;
			if(m1[i][j].g < min.g) min.g = m1[i][j].g;
			if(m1[i][j].b < min.b) min.b = m1[i][j].b;
			
			if(m1[i][j].r > max.r) max.r = m1[i][j].r;
			if(m1[i][j].g > max.g) max.g = m1[i][j].g;
			if(m1[i][j].b > max.b) max.b = m1[i][j].b;
		}
		
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++)
		{
			// Calcular os novos RGBs
			m2[i][j].r = ((m1[i][j].r - min.r) * 255) / (max.r - min.r);
			m2[i][j].g = ((m1[i][j].g - min.g) * 255) / (max.g - min.g);
			m2[i][j].b = ((m1[i][j].b - min.b) * 255) / (max.b - min.b);
		}
}

// Função para calcular o efeito "cinza"
void escalaCinza(Rgb m1[MAX][MAX], Rgb m2[MAX][MAX], int colunas, int linhas)
{
	int i, j;
	
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++)
		{
			// Calcular os novos RGBs
			m2[i][j].r = (m1[i][j].r + m1[i][j].g + m1[i][j].b) / 3;
			m2[i][j].g = m2[i][j].r;
			m2[i][j].b = m2[i][j].r;
		}
}

int main(int argc, char **argv)
{
	// Checar se os parâmetros foram inseridos corretamente
    if (argc != 3)
	{
      fprintf(stderr, "Argumentos invalidos.\n");
      fprintf(stderr, "Usado:");
      
      for(int i = 0; i < argc; i++) fprintf(stderr, " %s", argv[i]);
      fprintf(stderr, "\n");
      
      return 1;
    }
    
    // Declarar variáveis
    char efeito[20];
    char *arqEntrada = argv[1];
    char *arqSaida = argv[2];
    Rgb m1[MAX][MAX], m2[MAX][MAX];
    int colunas, linhas;

	// Escolher o efeito segundo o usuário
	printf("Efeito \"cinza\" ou \"esticar\"? ");
    scanf("%s", efeito);
    
    // Ler o arquivo de entrada
    lerImagem(arqEntrada, m1, &colunas, &linhas);
    
    // Aplicar o efeito que o usuário escolheu
    if(strcmp(efeito, "cinza") == 0)
		escalaCinza(m1, m2, colunas, linhas);
		
    else if(strcmp(efeito, "esticar") == 0)
		esticarContraste(m1, m2, colunas, linhas);
    
    // Imprimir o resultado no arquivo de saída
	escreverImagem(arqSaida, m2, colunas, linhas);

    return 0;
}
