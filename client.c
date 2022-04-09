#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h> 
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"    

void send_data(char c, int pid)
{
	c = 's';
	
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	ac = 4;
	int a;

	a = ft_atoi(av[1]);
	while (*av[2])
		send_data(*av[2]++, a);
}
