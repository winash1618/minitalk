#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void handler1(int sig_val)
{
	ft_printf("%d", 0);
}
int main()
{
	pid_t my_pid;
	my_pid = getpid();
	// printf("%d", my_pid);
 	// fflush(stdout);
	ft_printf("pid : %d\n", my_pid);
	// we need to use ft_printf since 
	// printf won't work without fflush and also 
	// printf is not allowed.
	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler1);
	while(1)
	{

	}
	
	
	
}