/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 03:25:23 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:44:29 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_charcheck(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_putaddr(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putint(va_arg(ap, int));
	else if (c == 'u')
		len += ft_putunint(va_arg(ap, unsigned int));
	else if (c == 'X')
		len += ft_puthexcap(va_arg(ap, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(ap, unsigned int));
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
			len += ft_charcheck(str[++i], ap);
		i++;
	}
	va_end(ap);
	return (len);
}
