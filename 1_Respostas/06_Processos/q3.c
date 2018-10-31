#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char  *argumento[2] = {NULL, NULL};
	pid_t pid_filho;

	for (int i = 1; i < argc; ++i)
	{
		pid_filho = fork();
		if (pid_filho == 0)
		{
			argumento[0] = (char *)argv[i];
			execvp(argumento[0], argumento);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}


	return 0;
}