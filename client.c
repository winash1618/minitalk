/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/27 07:08:44 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

bool	g_flag = false;

int	ft_matoi(const char *str)
{
	int				sign;
	unsigned long	sum;

	sign = 1;
	sum = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if ((sum > 2147483648 && sign == -1) || (sum > 2147483647 && sign == 1))
			return (-1);
	}
	if (*str)
		return (-1);
	return (sum * sign);
}

void	ft_err(void)
{
	ft_printf("Invalid Process ID!!!");
	exit (1);
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
	int time;

	index = 7;
	time = 0;
	// usleep(2);
	while (index >= 0)
	{
		// if (kill(pid, SIGUSR2 - (character >> index & 1)) == -1)
		// 	ft_err();
		while (1)
		{
			usleep(2);
			int j = kill(pid, SIGUSR2 - (character >> index & 1));
			if (j == 0)
				break ;
			else if (j == -1)
			{
				ft_printf("Client PID is invalid\n");
				exit(0);
			}	
		}
		index--;
		g_flag = true;
		while (g_flag)
		{
			usleep(2);
			time++;
			if (time > 10000)
			{
				time = 0;
				ft_printf("hi");
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
