/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:36:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/01 07:33:37 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				count;
	unsigned int	sum;

	count = 1;
	sum = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count = -count;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	if (sum > 2147483648 && count == -1)
		return (0);
	else if (sum > 2147483647 && count == 1)
		return (-1);
	return (sum * count);
}
