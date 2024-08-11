/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:20:46 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:44:48 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Handles the printting of a given
 * string to the standard output.
 * 
 * @param string The string to be print.
 * @return size_t The number of char that
 * were print.
 */
size_t	handle_str(const char *string)
{
	size_t	length;

	length = 0;
	if (!string)
		return (write(1, "(null)", 6));
	while (string[length])
		handle_char(string[length]);
	return (length);
}
