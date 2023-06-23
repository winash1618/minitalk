#include "libft.h"

t_dlist	*ft_dlstnew(pid_t pid)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->pid = pid;
	new->character = '\0';
	new->index = 0;
	return (new);
}