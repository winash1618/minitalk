/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:36:02 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/11 11:10:27 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	isneedle(const char *haystack, const char *needle, size_t len)
{
	int		c;
	size_t	count1;

	c = 0;
	count1 = 0;
	while (*haystack && *needle && *haystack == *needle && len)
	{
		haystack++;
		needle++;
		count1++;
		len--;
	}
	if (!*needle)
		c = 1;
	needle = needle - count1;
	haystack = haystack - count1;
	if (c)
		return (count1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;
	size_t	count;

	l = len;
	count = 0;
	if (!(*haystack) && l)
		if (*needle)
			return (NULL);
	if (!(*needle) || !(*haystack))
		return ((char *) haystack);
	while (l && *haystack && *needle)
	{
		if (isneedle(haystack, needle, l))
			return ((char *) haystack);
		haystack++;
		count++;
		l--;
	}
	return (NULL);
}
