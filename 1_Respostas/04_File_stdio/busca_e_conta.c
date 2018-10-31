#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main(int argc, char *argv[]){
	char *texto;
	int N, i, k, conta = 0;

	if(argc < 3){
		printf("Erro");
		return -1;
	}
	N = tam_arq_texto(argv[2]);
	texto = (char *)malloc(N+1);

	le_arq_texto(argv[2], texto);

	for (int i = 0; i < N; i++){
		k = 0;
		while((argv[1][k]!='\0') && (texto[i+k]!='\0') && (texto[i+k]==argv[1][k])){
			k++;
		}
		if(argv[1][k]=='\0'){
			conta++;
		}
	}

	free(texto);
	
	printf("'%s' ocorre %d vezes no arquivo '%s'\n",argv[1], conta, argv[2]);
	return 0;
}