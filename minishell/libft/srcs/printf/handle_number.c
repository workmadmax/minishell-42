/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:15:22 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:44:24 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Handles the printting of a given
 * number to the standard output.
 * 
 * @param nbr The number to be print.
 * @return size_t The number of charactes
 * that were printed.
 */
size_t	handle_num(long long nbr)
{
	size_t	length;

	length = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		length++;
		length += handle_num(nbr * (-1));
	}
	else if (nbr >= 0 && nbr <= 9)
		length += handle_char(nbr + 48);
	else
	{
		length += handle_num(nbr / 10);
		length += handle_num(nbr % 10);
	}
	return (length);
}
