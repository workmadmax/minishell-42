/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:12:58 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:54:31 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Computes the length of the string
 * 'str' up to, but not including the
 * terminating null character '\0'.
 * @param str This is the string whose length.
 * is to be found.
 * @return This function returns the length of string.
*/
size_t	ft_strlen(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}
