#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	for (int i = 1; i < argc; ++i)
	{
		system(argv[i]);
		//printf("\n");
	}
		
	return 0;
}