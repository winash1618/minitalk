#include "libft.h"

void	ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list *tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
}