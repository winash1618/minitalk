/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:51:04 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:51:16 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunint(unsigned int n)
{
	int	mod;
	int	len;

	len = 0;
	mod = n % 10;
	if (n > 9)
	{
		n = n / 10;
		len += ft_putint(n);
	}
	len += ft_putchar(mod + '0');
	return (len);
}
