/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:50:27 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:53:01 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Allocates (with malloc(3)) and return a new string,
 * wich is the result of the concatenation of 's1' and 's2'.
 * @param string_one The prefix string.
 * @param string_two The suffix string.
 * @return pointer to the first char of the
 * concatenated string.
*/
char	*ft_strjoin(char const *string_one, char const *string_two)
{
	char	*string;
	char	*ptr_str;

	if (!string_one || !string_two)
		return (NULL);
	string = (char *)malloc((ft_strlen(string_one)
				+ ft_strlen(string_two) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	ptr_str = string;
	while (*string_one)
		*string++ = *string_one++;
	while (*string_two)
		*string++ = *string_two++;
	*string = '\0';
	return (ptr_str);
}
