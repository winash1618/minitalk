/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:42:18 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 05:01:19 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the passed character is a printable character
 * 
 * @param c, the character to be checked
 * @return int, true if the character is a printable character, false otherwise
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
