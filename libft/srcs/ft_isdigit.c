/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:41:18 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 04:58:58 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the passed character is a digit
 * 
 * @param c, the character to be checked
 * @return int, true if the character is a digit, false otherwise
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
