/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:16:54 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:40:26 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Converts lowercase letter to uppercase.
 * 
 * @param c This is the letter to be converted
 * to uppercase.
 * @return This function return uppercase
 * equivalent to c,
 * if such value exists,
 * else c remains unchanged.
 * The value is returnd as an 'int' value 
 * that can be implicitly casted to 'char'.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
