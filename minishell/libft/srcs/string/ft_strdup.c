/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:43:47 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:51:16 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Function returns a pointer to
 * a new string which is a duplicate of the string 's'.
 * Memory for the new string is obtained with 'malloc',
 * and can be freed with 'free'.
 * 
 * @param string ponter to the start of the string to be copied.
 * @return It returns a pointer to the duplicated string 's'.
*/
char	*ft_strdup(const char *string)
{
	char	*copy_str;
	size_t	size;

	size = ft_strlen(string) + 1;
	copy_str = (char *)malloc(size);
	if (copy_str == NULL)
		return (NULL);
	ft_strlcpy(copy_str, string, size);
	return (copy_str);
}
