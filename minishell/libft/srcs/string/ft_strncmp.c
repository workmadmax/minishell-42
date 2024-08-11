/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:15:13 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:55:46 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Compares two strings character by
 * character, up to a maximum number of
 * characters.
 * 
 * @param string_one Pointer to the first string.
 * @param string_two Pointer to the second string.
 * @param n Maximum number of characters to compara.
 * @return int If Return value < 0 then it indicates
 * 'str1' is less than 'str2'.
 * If Return value > 0 then it indicates 'str2'
 * is less than 'str1'.
 * If Return value = 0 the in indicates 'str1'
 * is equal 'str2'.
 */
int	ft_strncmp(const char *string_one, const char *string_two, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str1 = (unsigned char *)string_one;
	str2 = (unsigned char *)string_two;
	while ((str1[index] || str2[index]) && index < n)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
	}
	return (0);
}
