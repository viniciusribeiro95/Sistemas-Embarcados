#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    FILE * fp; // Declaracao da estrutura
    fp=fopen ("ola_mundo.txt","w");  /* o arquivo se chama exemplo.bin e esta
                                       localizado no diretório corrente */
    char string[] = {"Olá mundo!\n"};
    
    if (!fp) printf("Erro na abertura do arquivo.");
    fprintf(fp, "%s\n", string);
       	
    fclose (fp);
    return 0;
}