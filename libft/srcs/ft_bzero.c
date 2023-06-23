/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:59:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 16:28:13 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets the first n bytes of the memory area pointed to by s to zero (bytes containing '\0')
 * 
 * @param s pointer to the memory area to be set
 * @param n number of bytes to be set to zero
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
