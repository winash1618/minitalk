/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:45:57 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 05:18:16 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	if (!c)
		return ((char *)s + count);
	while (count--)
		if (s[count] == (char) c)
			return ((char *)s + count);
	return (NULL);
}
