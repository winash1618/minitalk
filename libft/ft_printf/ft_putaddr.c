/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 07:41:26 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:50:02 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlonghex(unsigned long long longhex)
{
	int	mod;
	int	len;

	len = 0;
	if (longhex)
	{
		mod = longhex % 16;
		longhex /= 16;
		len += ft_putlonghex(longhex);
		if (mod < 10)
			len += ft_putchar(mod + '0');
		else
			len += ft_putchar(mod + 'a' - 10);
	}
	return (len);
}

int	ft_putaddr(unsigned long long addr)
{
	int	len;

	len = ft_putstr("0x");
	if (addr == 0)
		len += ft_putchar('0');
	else
		len += ft_putlonghex(addr);
	return (len);
}
