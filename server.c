/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/12 14:38:43 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void	killer(siginfo_t *siginfo)
{
	usleep(300);
	kill(siginfo->si_pid, SIGUSR1);
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			killer(siginfo);
		i = 0;
		c = 0;
	}
	siginfo->si_pid++;
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa1;
	struct sigaction	sa2;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("Ok,let's go - Here's my pid (%d). \n", pid);
		sa1.sa_flags = SA_SIGINFO;
		sa1.sa_sigaction = handler;
		sigemptyset(&sa1.sa_mask);
		sa2.sa_flags = SA_SIGINFO;
		sa2.sa_sigaction = handler;
		sigemptyset(&sa2.sa_mask);
		sigaction(SIGUSR1, &sa1, NULL);
		sigaction(SIGUSR2, &sa2, NULL);
		while (1)
			pause();
	}
	else
		ft_putendl_fd("Wrong Number of arguments", 2);
	return (0);
}
