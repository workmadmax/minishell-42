/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:14:35 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:13:01 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Checkes whether the passed
 * character is printable. 
 * A printable character is a character
 * that is not a control character.
 * @param c This is the character to be checked.
 * @return This function returns a
 * non-zero value(true)
 * if c is a printable
 * character else, zero (false).
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 127)
		return (1);
	else
		return (0);
}
