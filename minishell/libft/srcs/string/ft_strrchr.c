/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:32:04 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:56:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Searches for the last occurrence of a
 * given character in a string.
 * 
 * @param c Pointer to the string to search.
 * @return char* A pointer to the character found,
 * or NULL if the character is not found.
 */
char	*ft_strrchr(const char *string, int c)
{
	int	index;

	index = 0;
	while (string[index])
		index++;
	while (index >= 0)
	{
		if (string[index] == (char)c)
			return ((char *)(string + index));
		index--;
	}
	return (NULL);
}
