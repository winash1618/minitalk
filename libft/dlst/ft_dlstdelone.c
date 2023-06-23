#include "libft.h"

void	ft_dlstdelone(t_dlist **head, pid_t pid)
{
	t_dlist *node;
	t_dlist *temp;

	if (!head || !*head)
		return ;
	node = *head;
	while (node->next)
	{
		if(node->next->pid == pid)
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp);
			return ;
		}
		node = node->next;
	}
}