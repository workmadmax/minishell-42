/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:27:38 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:35:51 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Copies 'n' characters from 'str2'  to 'str1',
 *  but for overlapping memory blocks,
 * 'memmove()' is a safer approach than 'memcpy()'.
 * 
 * @param str1 This is a pointer to the destination
 * array where the content is to be copied,
 * type-casted to a pointer of type void*.
 * @param str2 This is a pointer to the sourcer
 * of data to be copied,
 * type-casted to a pointer of type void*.
 * @param n This is the number of bytes
 * to be copied.
 * @return This function returns a pointer
 * to the destination, which is str1.
*/
void	*ft_memmove(void *string_one, const void *string_two, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *)string_one;
	src = (char *)string_two;
	if (dest < src)
	{
		while (n > 0)
		{
			dest[n] = src[n];
			n--;
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
