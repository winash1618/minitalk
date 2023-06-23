/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:17:22 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 16:38:11 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the character c to the given file descriptor.
 * 
 * @param c character to output
 * @param fd file descriptor on which to write
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
