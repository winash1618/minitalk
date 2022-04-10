#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

// void	handler(int sig_val)
// {
// 	static int i;
// 	static char c;

// 	if (sig_val == SIGUSR1)
// 	{
// 		c = (c << 1) | 1;
// 	}
// 	else if (sig_val == SIGUSR2)
// 	{
// 		c = (c << 1) | 0;
// 	}
// 	i++;
// 	if(i == 8)
// 	{
// 		ft_printf("%c", c);
// 		i = 0;
// 		c = 0;
// 	}

// }

// int main()
// {
// 	pid_t my_pid;
// 	my_pid = getpid();
// 	// printf("%d", my_pid);
//  	// fflush(stdout);
// 	ft_printf("pid : %d\n", my_pid);
// 	// we need to use ft_printf since 
// 	// printf won't work without fflush and also 
// 	// printf is not allowed.
// 	signal(SIGUSR1, handler);
// 	signal(SIGUSR2, handler);
// 	while(1)
// 	{

// 	}
// }

void send_data(char *str, int pid)
{
	char c;

	while (*str)
	{
		c = *str++;
	int i;

	i = 8;
	while (--i >= 0)
	{
		if ((c >> i & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
	}
}

void handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	c;
	static int	counter;
	char		*str;

	str = (void *)context;
	if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (sig == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	i++;
	if(i == 8)
	{
		
		ft_printf("%c", c);
		i = 0;
		c = 0;
		counter++;
		if(c == '\0')
		{
			usleep(150);
			send_data("Thank you for sending", siginfo->si_pid);
			send_data(ft_itoa(counter), siginfo->si_pid);
		}
	}
	printf("your PID is %d\n", siginfo->si_pid);
}


int main()
{
	int pid;
	struct sigaction sa1;
	struct sigaction sa2;

	pid = getpid();
	ft_printf("Ok,let's go - Here's my pid (%d). \n",pid);
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = handler;
	sigemptyset(&sa1.sa_mask);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = handler;
	sigemptyset(&sa2.sa_mask);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while(1)
	{
	}
	return(0);
}