/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:58:33 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:41:23 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Process a 'format' specifier.
 * 
 * @param args A variable argument list.
 * @param format The 'format' specifier char.
 * @return size_t The total number of char
 * printed.
 */
size_t	ft_parse(va_list args, char format)
{
	size_t	length;

	length = 0;
	if (format == 'c')
		length += handle_char(va_arg(args, int));
	if (format == 's')
		length += handle_str(va_arg(args, char *));
	if (format == 'p')
		length += handle_hex(va_arg(args, unsigned long), 1, 0);
	if (format == 'd' || format == 'i')
		length += handle_num(va_arg(args, int));
	if (format == 'u')
		length += handle_num(va_arg(args, unsigned int));
	if (format == 'x')
		length += handle_hex(va_arg(args, unsigned int), 0, 0);
	if (format == 'X')
		length += handle_hex(va_arg(args, unsigned), 0, 1);
	if (format == '%')
		length += handle_char('%');
	return (length);
}
