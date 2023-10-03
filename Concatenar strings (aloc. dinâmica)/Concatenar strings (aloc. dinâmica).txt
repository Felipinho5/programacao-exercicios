#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char *concatena(char s1[], char s2[]);
void tirarEnter(char s[]);

int main()
{
	char s1[MAX], s2[MAX], *sres;
	
	printf("Insira um texto:\n");
	fgets(s1, MAX, stdin);
	printf("\n");
	
	printf("Insira um texto:\n");
	fgets(s2, MAX, stdin);
	printf("\n");
	
	tirarEnter(s1);
	tirarEnter(s2);
	
	sres = concatena(s1, s2);
	printf("%s", sres);
	free(sres);
	
	return 0;
}

char *concatena(char s1[], char s2[])
{
    char *sres = NULL;
    int t1, t2, i;
    
    t1 = strlen(s1);
    t2 = strlen(s2);
    
    sres = (char*)malloc( (t1 + t2 + 1) * sizeof(char) );
    
    for(i = 0; i < t1; i++) sres[i] = s1[i];
    for(i = 0; i < t2; i++) sres[i + t1] = s2[i];
    
    sres[t1 + t2] = '\0';
    return sres;
}

void tirarEnter(char s[])
{
	int tam;
	tam = strlen(s);
	
    if(s[tam-1] == '\n')
		s[tam-1] = '\0';
}