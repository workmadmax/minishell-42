/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:47:03 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:51:43 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Applies the function 'f' on each
 * character of the string passed as argument,
 * passing its index as first argument.
 * Each character is passed by adress to 'f'
 * to be modified if necessary.
 * 
 * @param string The string on which to iterate.
 * @param f The function to apply to each character.
 * @return None.
*/
void	ft_striteri(char *string, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (string == NULL || f == NULL)
		return ;
	index = 0;
	while (string[index] != '\0')
	{
		f(index, &string[index]);
		index++;
	}
}
