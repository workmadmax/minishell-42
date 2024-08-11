/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:06:41 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:11:06 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Checks if the passed character
 * is alphanumeric.
 * @param c This is the character to be checked.
 * @return This function returns non-zero value
 * if 'c' is a digit or a letter,
 * else it returns 0.
*/
int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) != 0 || ft_isdigit(c) != 0))
		return (1);
	else
		return (0);
}
