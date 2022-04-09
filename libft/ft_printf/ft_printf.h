/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:45:45 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/03/04 08:45:50 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);
int	ft_charcheck(char c, va_list ap);
int	ft_putlonghex(unsigned long long longhex);
int	ft_putaddr(unsigned long long addr);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putint(int num);
int	ft_putunint(unsigned int num);
int	ft_puthex(unsigned int hex);
int	ft_puthexcap(unsigned int hex);

#endif
