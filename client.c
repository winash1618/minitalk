/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/22 08:34:24 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int	g_flag = 0;

void	ft_err(int pid)
{
	if (pid <= 0)
	{
		ft_printf("Enter correct pid");
		exit (1);
	}
}

void	handler(int sig)
{
	static int recd_bit;
	static int recd_char;

	if (sig == SIGUSR1)
	{
		recd_bit++;
		g_flag = 0;
		if (recd_bit == 8)
		{
			recd_char++;
			recd_bit = 0;
		}
	}
	else
	{
		ft_printf("Thank you, recieved %d characters", recd_char - 1);
		exit (1);
	}
}

void	send_data(char character, int pid)
{
	int	index;

	index = 8;
	while (--index >= 0)
	{
		if ((character >> index & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		g_flag = 1;
		while (g_flag)
			usleep(10);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_err(pid);
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		while (av[2][i])
			send_data(av[2][i++], pid);
		send_data('\0', pid);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Wrong Number of arguments", 2);
}
