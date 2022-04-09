/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:58:07 by mkaruvan          #+#    #+#             */
/*   Updated: 2021/12/25 15:32:16 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	count = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (*str1 && *str2 && *str1 == *str2 && n > 0)
	{
		str1++;
		str2++;
		count++;
		n--;
	}
	if (n)
	{
		return (*str1 - *str2);
	}
	str1 = str1 - count;
	str2 = str2 - count;
	return (0);
}
