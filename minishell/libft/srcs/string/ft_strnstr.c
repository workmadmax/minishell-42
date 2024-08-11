/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:24:20 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:56:09 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Searches for a string within another
 * string, up to a maximum length.
 * 
 * @param big Pointer to the string in which to search.
 * @param little Pointer to the string to search for.
 * @param len Maximum length to search.
 * @return char* A pointer to the first occurence of
 * little within big, or NULL if little is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	count;

	if (little[0] == '\0')
		return ((char *)little);
	index = 0;
	while (little[index] != '\0' && index < len)
	{
		count = 0;
		while ((little[index + count] == big[count]) && (index + count) < len)
		{
			if (big[count + 1] == '\0')
				return ((char *)(&little[index]));
			count++;
		}
		index++;
	}
	return (NULL);
}
