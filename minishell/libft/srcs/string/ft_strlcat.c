/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:59:24 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:53:38 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Concatenates a string to the
 * end of another string, up to a
 * maximum number of characters.
 * 
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @param size Maximum number of characters to
 * append to the destination.
 * @return size_t Maximum number of characters to
 * append to the destination string.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	index;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	index = 0;
	if (size <= dest_len || size == 0)
		return (src_len + size);
	while (src[index] && dest_len < (size - 1))
	{
		dest[dest_len] = src[index];
		dest_len++;
		index++;
	}
	dest[dest_len] = '\0';
	return (src_len + dest_len - index);
}
