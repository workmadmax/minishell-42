/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:04:52 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:32:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Searches for the first occurrence of
 * a specific character in a block of memory;
 * 
 * @param ptr Pointer to the block of memory
 * to search.
 * @param c Character to search for.
 * @param len Number of bytes to searc.
 * @return void* A pointer to the firts occurrence
 * of the character in the block of memory,
 * or NULL if the character was not found.
 */
void	*ft_memchr(const void *ptr, int c, size_t len)
{
	unsigned char	*str;

	while (len -- > 0)
	{
		str = (unsigned char *)ptr;
		if (*str == (unsigned char) c)
			return (str);
		ptr++;
	}
	return (NULL);
}
