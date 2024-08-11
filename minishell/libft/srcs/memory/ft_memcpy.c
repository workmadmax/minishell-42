/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:22:10 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:34:06 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Copies 'n' bytes from the memory
 * area pointed to by 'src' to the memory
 * area pointed to by 'dest'.
 * 
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to copy
 * @return void* A pointer to the destination memory area.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		mem_dest[index] = mem_src[index];
		index++;
	}
	return (dest);
}
