#include "libft.h"

void	ft_dlstadd_back(t_dlist **olst, t_dlist *nlst)
{
	t_dlist *tmp;

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