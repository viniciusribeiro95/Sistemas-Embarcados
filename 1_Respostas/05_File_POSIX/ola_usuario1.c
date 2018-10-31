#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char nomearq[50], nome[50];
	int fp, i=0, idade;

	printf("Digite o seu nome: ");
	scanf("%s", nome);

	printf("Digite sua idade: ");
	scanf("%d", &idade);

	while(nome[i] != '\0'){
		nomearq[i] = nome[i];
		i++;
	}
	strcat(nomearq,".txt");
	fp = open(nomearq, O_RDWR | O_CREAT, S_IRWXU);

	write(fp, "Nome: ", 6);
	while(write(fp, nome, 1) != -1){
		write(fp, nome, 1);
	}
	write(fp, "\n", 1);
	
	close(fp);
	return 0;
}