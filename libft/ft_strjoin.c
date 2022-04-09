/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:11:09 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/01 10:34:29 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count1;
	int		count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	str = (char *) ft_calloc((count1 + count2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, count1);
	ft_memcpy(str + count1, s2, count2);
	return (str);
}
