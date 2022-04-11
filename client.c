/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/11 10:48:16 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int	g_count;

void	ft_error(int flag, char **av)
{
	int	a;

	a = ft_atoi(av[1]);
	if (flag == 1 && a < 100 && a > 99999)
	{
		ft_printf("Enter Correct pid");
	}
	else if (flag == 0)
	{
		ft_printf("You need enter 3 arguements in a format as given below \n");
		ft_printf("./client PID_SERVER STRING_TO_PASS");
	}
	exit(1);
}

void	handler(int sig_val)
{
	if (sig_val == SIGUSR1)
		ft_printf("Thank you, recieved %d characters", g_count);
	exit (1);
}

void	send_data(char c, int pid)
{
	int	i;

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
	int	a;
	int	i;

	i = 0;
	if (ac == 3)
	{
		a = ft_atoi(av[1]);
		ft_error(1, av);
		while (av[2][i])
		{
			send_data(av[2][i], a);
			i++;
		}
		send_data('\0', a);
		g_count = ft_strlen(av[2]);
		signal(SIGUSR1, handler);
		while (1)
			pause();
	}
	else
		ft_error(0, av);
}
