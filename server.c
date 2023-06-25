/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/25 10:42:25 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

t_dlist *char_store;

void killer(pid_t client_pid)
{
	t_dlist *node;
	t_dlist *temp;

	node = char_store;
	usleep(50);
	while (node)
	{
		if (node->pid == client_pid && char_store == node)
		{
			char_store = node->next;
			free(node);
			node = NULL;
			if (kill(client_pid, SIGUSR2) == -1)
			{
				ft_printf("Client Pid is invalid\n");
				exit(0);
			}
			return ;
		}
		if (node->next && node->next->pid == client_pid)
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp);
			temp = NULL;
			if (kill(client_pid, SIGUSR2) == -1)
			{
				ft_printf("Client Pid is invalid\n");
				exit(0);
			}
			return ;
		}
		node = node->next;
	}
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
			return ;
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
					return ;
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
				return ;
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
	if (kill(client_pid, SIGUSR1) == -1)
	{
		ft_printf("Client Pid is invalid\n");
		exit(0);
	}
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
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error registering SIGUSR signal handler.\n");
		return 1;
	}
	while (1)
		pause();
	return (0);
}
