/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/12 14:41:30 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int	g_count;

void	ft_err(int pid, int flag)
{
	if (flag == -1)
	{
		ft_printf("Enter correct pid");
		exit (1);
	}
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
	int	j;

	i = 8;
	j = 0;
	while (--i >= 0)
	{
		if ((c >> i & 1) == 1)
			j = kill(pid, SIGUSR1);
		else
			j = kill(pid, SIGUSR2);
		usleep(150);
	}
	ft_err(pid, j);
}

int	main(int ac, char **av)
{
	int	a;
	int	i;

	i = 0;
	if (ac == 3)
	{
		a = ft_atoi(av[1]);
		ft_err(a, 0);
		while (av[2][i])
			send_data(av[2][i++], a);
		send_data('\0', a);
		g_count = ft_strlen(av[2]);
		signal(SIGUSR1, handler);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Wrong Number of arguments", 2);
}
