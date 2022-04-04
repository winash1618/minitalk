#include<stdio.h>
#include<wait.h>
#include<signal.h>
int main()
{
	int stat;
	pid_t pid;
	if ((pid = fork()) == 0)
		while(1) ;
	else
	{
		kill(pid, SIGINT);
		wait(&stat);
		if (WIFSIGNALED(stat))
			psignal(WTERMSIG(stat), "Child term due to");
	}
}

// here if you remove kill which is sending signal to the process itself 
// this will end the process by interrupt. if there is no kill then it will untill the 
// cpu time limit.