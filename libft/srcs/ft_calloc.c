/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:09:16 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/02/02 16:37:38 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory for an array of count elements of 
 * size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * 
 * @param count number of elements
 * @param size size of each element
 * @return void* pointer to the allocated memory
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
