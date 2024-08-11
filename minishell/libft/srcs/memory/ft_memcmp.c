/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:10:38 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:33:26 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief compares the first 'n' bytes
 * of memory area 'str1' and memory area 'str2'.
 * 
 * @param string_one This is the pointer to a block of memory.
 * @param string_two This is the pointer to a block of memory.
 * @param n This is the number of bytes to compared.
 * @return if Return value < 0 then it indicates 'str1'
 * is less than 'str2'.
 * if Return value > 0 then it indicates 'str2'
 * is less than 'str1'.
 * if Return value = 0 then it indicates 'str1'
 * is equal to 'str2'.
*/
int	ft_memcmp(const void *string_one, const void *string_two, size_t n)
{
	size_t			index;
	unsigned char	*str_one;
	unsigned char	*str_two;

	index = 0;
	str_one = (unsigned char *)string_one;
	str_two = (unsigned char *)string_two;
	while (index < n)
	{
		if (str_one[index] != str_two[index])
			return ((int)(str_one[index] - str_two[index]));
		if (n == 0)
			return ((int)n);
		index++;
	}
	return (0);
}
