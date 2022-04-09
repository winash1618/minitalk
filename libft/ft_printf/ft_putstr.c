/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 07:42:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:47:19 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
		len += ft_putchar(str[i++]);
	return (len);
}
