/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:54:23 by mkaruvan          #+#    #+#             */
/*   Updated: 2021/12/23 09:54:06 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*k;

	k = b;
	count = 0;
	while (len)
	{
		*k++ = (unsigned char)c;
		count++;
		len--;
	}
	return (k - count);
}
