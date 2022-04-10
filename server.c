#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void handler(int sig_val)
{
	static int i;
	static char c;


	if (sig_val == SIGUSR1)
	{
		c = (c << 1) | 0;
		ft_printf(" %d", c);
	}
	else if (sig_val == SIGUSR2)
	{
		c = (c << 1) | 1;
		ft_printf(" %d", c);
	}
	i++;
	if(i == 8)
	{
		i = 0;
		c = 0;
	}

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
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	{

	}
	
	
	
}