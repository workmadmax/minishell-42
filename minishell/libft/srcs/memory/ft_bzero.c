/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:57:11 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:30:42 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Fills the first 'n' bytes of the project
 * pointed to by dest with zero (NUL) bytes.
 * 
 * @param dest An existing object that you want to fill whit zeroes.
 * @param n The number of bytes to fill.
*/
void	ft_bzero(void *dest, size_t n)
{
	ft_memset(dest, '\0', n);
}
