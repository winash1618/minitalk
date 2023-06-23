/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:39:24 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 05:00:29 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the passed character is an ASCII character
 * 
 * @param c, the character to be checked
 * @return int, true if the character is an ASCII character, false otherwise
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
