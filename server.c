/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/25 07:32:38 by mkaruvan         ###   ########.fr       */
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
			kill(client_pid, SIGUSR2);
			return ;
		}
		if (node->next && node->next->pid == client_pid)
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp);
			temp = NULL;
			kill(client_pid, SIGUSR2);
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
			ft_printf("If i am not coming here kill me\n");
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
					// ft_printf("hi i am here \n");
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
	// ft_printf("hid %d", siginfo->si_pid);
	if (siginfo->si_pid)
		check_list_and_reset(siginfo->si_pid, &i, &character, &client_pid);
	character = (character << 1) | (sig == SIGUSR1);
	i++;
	if (siginfo->si_pid)
		check_list_and_reset(siginfo->si_pid, &i, &character, &client_pid);
	// ft_printf("siginfo->si_pid = %d \n", siginfo->si_pid);
	usleep(50);
	kill(client_pid, SIGUSR1);
	if (i == 8)
	{
		i = 0;
		if (character == '\0')
		{
			printf("size before : %d\n", ft_dlstsize(char_store));
			killer(client_pid);
			printf("size after : %d\n", ft_dlstsize(char_store));
		}
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
