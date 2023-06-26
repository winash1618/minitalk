/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:27:38 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/26 08:41:34 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlstfind(t_dlist *head, pid_t pid)
{
	while (head)
	{
		if (head->pid == pid)
			return (1);
		head = head->next;
	}
	return (0);
}
