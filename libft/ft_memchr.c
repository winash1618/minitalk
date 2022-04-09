/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:58:52 by mkaruvan          #+#    #+#             */
/*   Updated: 2021/12/23 09:47:27 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;

	str = s;
	while (n)
	{
		if (*str == (unsigned char) c)
		{
			return ((void *) str);
		}
		str++;
		n--;
	}
	return (NULL);
}
