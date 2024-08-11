/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:15:09 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:55:01 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Applies the function 'f'
 * to each character of the string 's',
 * and passing its index as first argument
 * to create a new string (with malloc(3))
 * resulting from succesive applications of 'f'.
 * 
 * @param s The string on wich to iterate
 * @param f The function to apply to each character.
 * @return The string created from the successive
 * application of 'f'.
 * Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	if (!string)
		return (NULL);
	str = (char *)malloc((ft_strlen(string) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (string[index])
	{
		str[index] = f(index, string[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
