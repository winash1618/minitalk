/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/23 10:24:00 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

t_dlist *char_store;

void killer(pid_t client_pid)
{
	usleep(50);
	// if (ft_dlstfind(char_store, client_pid))
	// 	ft_dlstdelone(&char_store, client_pid); // this is not working fine
	kill(client_pid, SIGUSR2);
}

void check_list_and_reset(pid_t pid, int *index, unsigned char *character, pid_t *client_pid)
{
	t_dlist *temp;

	temp = char_store;
	if (*client_pid != pid)
	{
		if (!ft_dlstfind(char_store, pid))
		{
			ft_dlstadd_back(&char_store, ft_dlstnew(pid));
			*client_pid = pid;
			*index = 0;
			*character = '\0';
		}
		else
		{
			while (temp)
			{
				if (temp->pid == pid)
				{
					*character = temp->character;
					*index = temp->index;
					*client_pid = temp->pid;
				}
				temp = temp->next;
			}
		}
	}
	else
	{
		while (temp)
		{
			if (temp->pid == pid)
			{
				temp->character = *character;
				temp->index = *index;
			}
			temp = temp->next;
		}
	}
}

void handler(int sig, siginfo_t *siginfo, void *context)
{
	static int i;
	static unsigned char character;
	static pid_t client_pid;

	(void)context;
	if (siginfo->si_pid)
		check_list_and_reset(siginfo->si_pid, &i, &character, &client_pid);
	character = (character << 1) | (sig == SIGUSR1);
	i++;
	if (siginfo->si_pid)
		check_list_and_reset(siginfo->si_pid, &i, &character, &client_pid);
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

int main()
{
	int pid;
	struct sigaction sa;

	pid = getpid();
	ft_printf("Ok,let's go - Here's my pid (%d). \n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
