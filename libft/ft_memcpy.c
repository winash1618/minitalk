/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:08:13 by mkaruvan          #+#    #+#             */
/*   Updated: 2021/12/27 08:18:58 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*k;
	unsigned const char	*m;
	size_t				count;

	count = 0;
	k = dst;
	m = src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n)
	{
		*k++ = *m++;
		count++;
		n--;
	}
	m = m - count;
	return (k - count);
}
