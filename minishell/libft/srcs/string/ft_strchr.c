/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:40:41 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:50:41 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Searches for the first occurrence
 * of the character 'c' (an unsigned char)
 * in the string pointed to by the argument 'string'.
 * 
 * @param string This is the C string to be scanned.
 * @param c This is the character to be searched in str.
 * @return This returns a pointer to the first occurrence
 * of the character c in the string str,
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *string, int c)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *)string;
	while (str[index])
	{
		if (str[index] == c)
			return (&str[index]);
		index++;
	}
	if (c == '\0')
		return (&str[index]);
	return (0);
}
