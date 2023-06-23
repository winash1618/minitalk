/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:40:18 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/02 07:41:29 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	count2;
	size_t	temp;

	count = ft_strlen(dst);
	count2 = 0;
	temp = ft_strlen(src);
	if (count >= dstsize)
		return (dstsize + temp);
	dst = dst + count;
	temp = count + temp;
	dstsize = dstsize - count;
	while (*src && dstsize-- - 1)
	{
		*dst++ = *src++;
		count++;
		count2++;
	}
	*dst = '\0';
	src = src - count2;
	dst = dst - count;
	return (temp);
}
