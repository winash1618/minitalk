/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 07:42:07 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:49:12 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int hex)
{
	int	mod;
	int	len;

	len = 0;
	mod = hex % 16;
	if (hex > 15)
	{
		hex /= 16;
		len += ft_puthex(hex);
	}
	if (mod < 10)
		len += ft_putchar(mod + '0');
	else
		len += ft_putchar(mod + 'a' - 10);
	return (len);
}
