/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:59:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2021/12/27 11:20:55 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*k;
	size_t			count;

	k = s;
	count = 0;
	while (n)
	{
		*k++ = 0;
		n--;
		count++;
	}
	k = k - count - 1;
}
