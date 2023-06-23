/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:26:48 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/02 07:41:36 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (!(dstsize))
		return (ft_strlen(src));
	while (*src && dstsize - 1)
	{
		*dst++ = *src;
		count++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	src = src - count;
	dst = dst - count;
	return (ft_strlen(src));
}
