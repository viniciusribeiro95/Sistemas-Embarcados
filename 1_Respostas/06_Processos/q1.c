#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t child_pid1, child_pid2;

	child_pid1 = fork();
	child_pid2 = fork();
	if (child_pid1 == 0)
	{
		if(child_pid2 == 0)
		{
			printf("Sou o filho 3 \n");
		}
		else
		{
			printf("Sou o filho 2 \n");
		}
	}
	else
	{
		wait(NULL);
		if(child_pid2 == 0)
		{
			printf("Sou o filho 1 \n");
		}
		else
		{
			printf("Sou o Pai \n");
		}
		

	}
	return 0;
}