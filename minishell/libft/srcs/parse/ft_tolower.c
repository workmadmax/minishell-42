/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:18:50 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:40:06 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Coverts a given letter to lowercase.
 * 
 * @param c This is letter to be converted
 * to lowercase.
 * @return This function returns lowercase
 * equivalent to c,
 * if such value exists,
 * else c remains unchanged.
 * The value is returned as an 'int' value
 * that can be implicitly casted to 'char'.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
