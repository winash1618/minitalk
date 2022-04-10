#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h> 
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <stdio.h>    

void	handler(int sig_val)
{
	static int i;
	static char c;

	if (sig_val == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (sig_val == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	i++;
	if(i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

void send_data(char c, int pid)
{
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

int	main(int ac, char **av)
{
	ac = 4;
	int a;
	int i;

	i = 0;
	a = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_data(av[2][i], a);
		i++;
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{

	}
}
