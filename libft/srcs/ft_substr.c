/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:57:48 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/03 06:08:12 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len == ft_strlen(s))
		len = len - start;
	str = (char *) ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	while (s[start] && len)
	{
		str[i++] = s[start];
		start++;
		len--;
	}
	return (str);
}

// int main()
// {
// 	char *str = "0123456789";
// 	char *substr = ft_substr(str, 9, 10);
// 	return (0);
// }