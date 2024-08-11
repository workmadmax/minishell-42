/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:00:11 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:32:03 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Allocates memory for a block  of size
 * count * size bytes and initializes all
 * bytes of the block to zero.
 * 
 * @param count The number of elements.
 * @param size The size of each element.
 * @return void* A pointer to the allocated and
 * initialized block with zero, or zero if
 * the allocation fails.
 */
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*dest;

	total_size = size * count;
	dest = malloc(total_size);
	if (!dest)
		return (0);
	ft_memset(dest, 0, total_size);
	return (dest);
}
