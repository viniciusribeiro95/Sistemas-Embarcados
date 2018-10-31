#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main()
{
	pid_t child_pid[3];

	for (int i = 0; i < 3; ++i)
	{
		child_pid[i] = fork();
		if(child_pid[i] == 0)
		{
			Incrementa_Variavel_Global(getpid());
			return 0;
		}
		else
		{
			wait(NULL);
			Incrementa_Variavel_Global(getpid());
		}
	}



	return 0;
}
