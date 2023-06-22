/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/22 10:27:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

pid_t client_pid;

void	killer(pid_t client_pid)
{
	usleep(50);
	kill(client_pid, SIGUSR2);
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static unsigned char	character;

	(void)context;
	if (siginfo->si_pid)
		client_pid = siginfo->si_pid;
	character = (character << 1) | (sig == SIGUSR1);
	i++;
	usleep(50);
	kill(client_pid, SIGUSR1);
	if (i == 8)
	{
		i = 0;
		if (character == '\0')
			killer(client_pid);
		write(1, &character, 1);
		character = '\0';
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("Ok,let's go - Here's my pid (%d). \n", pid);
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Wrong Number of arguments", 2);
	return (0);
}
