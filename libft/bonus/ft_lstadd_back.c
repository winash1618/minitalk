#include "libft.h"
#include <stdio.h>
void	ft_lstadd_back(t_list **olst, t_list *nlst)
{
	t_list *tmp;

	if (!olst || !nlst)
		return ;
	if (*olst == NULL)
	{
		*olst = nlst;
		return ;
	}
	tmp = *olst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nlst;
}

