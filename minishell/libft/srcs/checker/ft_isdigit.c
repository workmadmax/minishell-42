/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:13:06 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:12:30 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Checks if the passed character
 * is a decimal digit character.
 * numbers (0 to 9).
 * 
 * @param c This the character
 * to be checked.
 * @return This function returns
 * non-zero value if 'c' is a digit,
 * else it returns 0.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
