/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:45:53 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/02 07:39:55 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*k;
	unsigned const char	*m;
	int					diff;
	int					length;

	diff = src - dst;
	length = (int)len;
	if (dst == NULL && src == NULL)
		return (dst);
	if (diff < length && diff > 0)
		return (ft_memcpy(dst, src, len));
	else
	{
		k = dst + len - 1;
		m = src + len - 1;
		while (len)
		{
			*k-- = *m--;
			len--;
		}
		k++;
		m++;
	}
	return (k);
}
