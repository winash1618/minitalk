/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:23:56 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/26 09:06:05 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi_base(const char *str, int str_base)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (str_base < 2 || str_base > 16)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'A' + str_base - 10) \
		|| (str[i] >= 'a' && str[i] <= 'a' + str_base - 10))
	{
		if (ft_isdigit(str[i]))
			result = result * str_base + (str[i] - '0');
		else
			result = result * str_base + (str[i] - 'A' + 10);
		i++;
	}
	return (result * sign);
}