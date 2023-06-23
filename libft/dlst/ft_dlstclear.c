#include "libft.h"

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist *tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(tmp);
		tmp = *lst;
	}
}