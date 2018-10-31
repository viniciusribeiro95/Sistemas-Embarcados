#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
	int tam = 0;
	FILE *fp;

	fp = fopen(nome_arquivo, "r");

	while(getc(fp)!= EOF){
		tam++;
	}

	fclose(fp);
	return tam;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	int tam_arq = 0;
	FILE *fp;

	fp = fopen(nome_arquivo, "r");
	tam_arq = tam_arq_texto(nome_arquivo);

	fread(conteudo, sizeof(char), tam_arq, fp);
	conteudo[tam_arq] = '\0';
	
	fclose(fp);
}