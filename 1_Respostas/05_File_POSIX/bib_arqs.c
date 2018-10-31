#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
	int fp, tam = 0;

	fp = open(nome_arquivo, O_RDONLY);

	while(read(fp)!= EOF){
		tam++;
	}

	close(fp);
	return tam;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	int fp, tam_arq = 0;

	fp = fopen(nome_arquivo, O_RDONLY);
	tam_arq = tam_arq_texto(nome_arquivo);

	read(conteudo, sizeof(char), tam_arq, fp);
	conteudo[tam_arq] = '\0';
	
	fclose(fp);
}