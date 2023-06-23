/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:37:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 04:59:22 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the passed character is an alphabet
 * 
 * @param c, the character to be checked
 * @return int, true if the character is an alphabet, false otherwise
 */
int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
