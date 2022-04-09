/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:45:57 by mkaruvan          #+#    #+#             */
/*   Updated: 2021/12/23 11:09:23 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	if (!c)
	{
		return ((char *)s + count);
	}
	while (count--)
	{
		if (s[count] == (char) c)
		{
			return ((char *)s + count);
		}
	}
	return (NULL);
}
