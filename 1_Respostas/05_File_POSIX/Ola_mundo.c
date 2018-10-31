#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
   
    char string[] = {"Olá mundo!\n"};
	int fp;
	fp = open("ola.txt",  O_RDWR | O_CREAT, S_IRWXU);
    
    if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
	for (int i = 0; string[i]; ++i)
	{
		write(fp, &(string[i]), 1);
	}
	
	close(fp);
    return 0;
}