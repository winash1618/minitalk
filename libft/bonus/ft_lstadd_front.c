#include "libft.h"

void	ft_lstadd_front(t_list **olst, t_list *nlst)
{
	if (!olst || !nlst)
		return ;
	if (*olst == NULL)
	{
		*olst = nlst;
		return ;
	}
	nlst->next = *olst;
	*olst = nlst;
}