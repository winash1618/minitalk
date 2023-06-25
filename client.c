/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/25 11:03:28 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

bool	g_flag = false;

void	ft_err()
{
	ft_printf("Invalid Process ID!!!");
	exit (1);
}

void	handler(int sig)
{
	static int recd_bit;
	static int recd_char;

	if (sig == SIGUSR1)
	{
		recd_bit++;
		usleep(20);
		g_flag = false;
		if (recd_bit == 8)
		{
			recd_char++;
			recd_bit = 0;
		}
	}
	else
	{
		ft_printf("Number of Character's recd = %d\n", recd_char - 1);
		exit (0);
	}
}

void	send_data(unsigned char character, int pid)
{
	int	index;
	// int time;

	index = 8;
	while (--index >= 0)
	{
		// time = 0;
		if (kill(pid, SIGUSR2 - (character >> index & 1)) == -1)
			ft_err();
		g_flag = true;
		while (g_flag)
		{
			usleep(10);
			// time += 1;
			// if (time > 300)
			// 	g_flag = false;
		}
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
		if (pid <= 0)
			ft_err();
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		ft_printf("Number of character's send = %d\n", ft_strlen(av[2]));
		while (av[2][i])
			send_data(av[2][i++], pid);
		send_data('\0', pid);
		usleep(500);
	}
	else
		ft_putendl_fd("Wrong Number of arguments", 2);
}
