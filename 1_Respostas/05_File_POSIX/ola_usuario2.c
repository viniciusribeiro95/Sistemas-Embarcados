#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE * fp;
	char nomearq[15], *nome, *idade;
	int i=0;

	nome = argv[1];
	idade = argv[2];

	while(argv[1][i] != '\0'){
		nomearq[i] = argv[1][i];
		i++;
	}

	strcat(nomearq,".txt");

	fp = fopen(nomearq, "w");

	fprintf(fp, "Nome: %s \n", nome);
	fprintf(fp, "Idade: %s anos\n", idade);
	
	fclose(fp);
	return 0;
}