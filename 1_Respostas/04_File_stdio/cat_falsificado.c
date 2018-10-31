#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_text(char *nome_arquivo);
void le_arq_texto(char *nome_arquivo, char *conteudo);

int main(int argc, char *argv[])
{
	char texto[100];
	if ((tam_arq_text(argv[1])+1) < (int)sizeof(texto)){
		le_arq_texto(argv[1], texto);
		printf("%s\n", texto);
	}
	else{
		printf("Arquivo muito grande!\n");
	}

	return 0;
}