/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:46:13 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:58:43 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Return a new string that is a substring
 * of the original src string,
 * starting at position start and
 * having a length of 'len' characters.
 * 
 * @param src The source string.
 * @param start The starting position of the
 * substring of 'src'.
 * @param len The length of the substring.
 * @return char* A new string cotaining the
 * substring of 'src', or zero if 'src' is
 * NULL or if it is not possible to
 * allocate memory for the new string.
 */
char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t	index;
	size_t	count;
	char	*new_str;

	if (!src)
		return (0);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (0);
	index = start;
	count = 0;
	while (index < ft_strlen(src) && count < len)
		new_str[count++] = src[index++];
	new_str[count] = '\0';
	return (new_str);
}
