#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
	int pid;
	int status;
	pid = fork();

	if (pid == 0)
	{
		printf("I am the child PID %d\n", getpid());
		sleep(10);
		exit(42);
	}
	else if (pid > 0)
	{
		printf("I am the parent, PID %d\n", getpid());
		printf("status: %d\n");
		wait(&status);
		printf("Child terminated status %d\n", WEXITSTATUS(status));
	}
	else
		perror("fork");

	return 0;
}
