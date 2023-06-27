/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/27 09:39:08 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

bool	g_flag = false;

void	ft_err(void)
{
	ft_printf("Invalid Server PID!!!");
	exit (1);
}

void	sender(int server_pid, int sig)
{
	int	j;

	j = 0;
	while (1)
	{
		usleep(2);
		j = kill(server_pid, sig);
		if (j == 0)
			break ;
		else if (j == -1)
			ft_err();
	}
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	recd_bit;
	static int	recd_char;

	(void) siginfo;
	(void) context;
	if (sig == SIGUSR1)
	{
		recd_bit++;
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
	int	count;

	index = 7;
	count = 0;
	while (index >= 0)
	{
		sender(pid, SIGUSR2 - (character >> index-- & 1));
		g_flag = true;
		while (g_flag)
		{
			usleep(2);
			count++;
			if (count > 10000)
			{
				count = 0;
				ft_printf("*");
				g_flag = false;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					index;
	struct sigaction	sa;

	index = 0;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (argc == 3)
	{
		pid = ft_matoi(argv[1]);
		if (pid <= 0)
			ft_err();
		if (sigaction(SIGUSR1, &sa, NULL) == -1 \
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
			return (ft_printf("Error registering SIGUSR signal handler.\n"));
		ft_printf("Number of character's send = %d\n", ft_strlen(argv[2]));
		while (argv[2][index])
			send_data(argv[2][index++], pid);
		send_data('\0', pid);
		usleep(500);
	}
	else
		ft_putendl_fd("Wrong Number of arguments", 2);
	return (1);
}
