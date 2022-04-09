/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 07:42:18 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:47:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n)
{
	int	mod;
	int	len;

	len = 0;
	if (n == -2147483647 - 1)
	{
		write(1, "-2147483648", 11);
		len += 11;
		return (len);
	}
	if (n < 0)
		len += ft_putchar('-');
	if (n < 0)
		n = n * -1;
	mod = n % 10;
	if (n > 9)
	{
		n = n / 10;
		len += ft_putint(n);
	}
	len += ft_putchar(mod + '0');
	return (len);
}
