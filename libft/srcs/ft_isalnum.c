/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:32:39 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 04:59:46 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the passed character is an alphabet or a digit
 * 
 * @param c, the character to be checked
 * @return int, true if the character is an alphabet or a digit, false otherwise
 */
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
