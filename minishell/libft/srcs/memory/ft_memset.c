/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:31:17 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:36:17 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Fills the first 'n' bytes of the memory
 * area pointed to by 'string' with the value 'c'
 * 
 * @param string A pointer to the memory area to be filled.
 * @param c The value to fill the memory area with.
 * @param n The number of bytes to fill.
 * @return void* A pointer to the memory area.
 */
void	*ft_memset(void *string, int c, size_t n)
{
	char		*aux;
	size_t		index;

	aux = (char *)string;
	index = 0;
	while (index < n)
	{
		aux[index] = c;
		index++;
	}
	return (string);
}
