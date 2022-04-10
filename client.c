/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/10 10:52:44 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int	g_count;

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
		while (av[2][i])
		{
			send_data(av[2][i], a);
			i++;
		}
		send_data('\0', a);
		g_count = ft_strlen(av[2]);
		signal(SIGUSR1, handler);
		while (1)
		{
		}
	}
}
