#include "libft.h"

int ft_dlstsize(t_dlist *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}