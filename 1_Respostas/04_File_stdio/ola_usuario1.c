#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE * fp;
	char nomearq[50], nome[50];
	int i=0, idade;

	printf("Digite o seu nome: ");
	scanf("%s", nome);

	printf("Digite sua idade: ");
	scanf("%d", &idade);

	while(nome[i] != '\0'){
		nomearq[i] = nome[i];
		i++;
	}
	strcat(nomearq,".txt");
	fp = fopen(nomearq, "w");

	fprintf(fp, "Nome: %s \n", nome);
	fprintf(fp, "Idade: %d anos\n", idade);
	
	fclose(fp);
	return 0;
}