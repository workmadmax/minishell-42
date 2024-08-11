/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:07:04 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:54:11 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Copies a string to another string,
 * up to a maximum number of characters.
 * 
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @param size Maximum number of characters to copy
 * to the destination string.
 * @return size_t The total length of the string
 * that the function tried to create.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (src[index] && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = 0;
	}
	while (src[index])
		index++;
	return (index);
}
