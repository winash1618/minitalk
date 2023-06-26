/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/26 16:48:45 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

t_dlist	*g_store;

void	feedback(int client_pid, int sig)
{
	usleep(20);
	if (kill(client_pid, sig) == -1)
	{
		ft_printf("Client Pid is invalid\n");
		exit(0);
	}
}

void	killer(pid_t client_pid)
{
	t_dlist	*node;
	t_dlist	*temp;

	node = g_store;
	while (node)
	{
		if (node->pid == client_pid && g_store == node)
		{
			g_store = node->next;
			free(node);
			node = NULL;
			feedback(client_pid, SIGUSR2);
			return ;
		}
		if (node->next && node->next->pid == client_pid)
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp);
			temp = NULL;
			feedback(client_pid, SIGUSR2);
			return ;
		}
		node = node->next;
	}
}

pid_t check_list_and_reset(pid_t pid, int *index, \
			unsigned char *character, pid_t *client_pid)
{
	t_dlist	*temp;
	// int i;

	temp = g_store;
	// i = 0;
	while (temp && temp->pid != pid)
	// {
	// 	i++;
	// 	if (i > 100)
	// 		ft_printf("Error : \n");
		temp = temp->next;
	// }
	if (*client_pid != pid)
	{
		if (!ft_dlstfind(g_store, pid))
		{
			temp = ft_dlstnew(pid);
			ft_dlstadd_back(&g_store, temp);
		}
		*character = temp->character;
		*index = temp->index;
	}
	else
	{
		temp->character = *character;
		temp->index = *index;
	}
	return (pid);
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				index;
	static unsigned char	character;
	static pid_t			client_pid;

	(void)context;
	if (siginfo->si_pid && siginfo->si_pid != client_pid)
		client_pid = check_list_and_reset(siginfo->si_pid, \
					&index, &character, &client_pid);
	character = (character << 1) | (sig == SIGUSR1);
	index++;
	if (siginfo->si_pid && siginfo->si_pid == client_pid)
		check_list_and_reset(siginfo->si_pid, \
			&index, &character, &client_pid);
	feedback(client_pid, SIGUSR1);
	if (index == 8)
	{
		index = 0;
		if (character == '\0')
			killer(client_pid);
		write(1, &character, 1);
		character = '\0';
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Ok,let's go - Here's my pid (%d). \n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
			sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error registering SIGUSR signal handler.\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
