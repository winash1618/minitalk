/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:27:45 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/01 07:41:58 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		*ptr++ = *s1++;
		count++;
	}
	*ptr = '\0';
	ptr = ptr - count;
	s1 = s1 - count;
	return (ptr);
}
