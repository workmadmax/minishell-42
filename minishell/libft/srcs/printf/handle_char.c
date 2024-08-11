/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:04:30 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:42:47 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Processes a character format specifier.
 * 
 * @param character The character to be printed.
 * @return size_t The number of char printed (1).
 */
size_t	handle_char(char character)
{
	write (1, &character, 1);
	return (1);
}
