/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:52:11 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:42:32 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Prints a formatted output to
 * the screen or to a file.
 * 
 * @param format A string containing
 * 'format' specifiers.
 * @param ... A variable number of arguments
 * to be formatted and printed.
 * @return int The total number of characters
 * printed.
 */
int	ft_printf(const char *format, ...)
{
	size_t	length;
	va_list	args;

	length = 0;
	va_start(args, format);
	if (!format)
	{
		va_end(args);
		return (0);
	}
	while (*format)
	{
		if (*format == '%')
			length += ft_parse(args, *++format);
		else
			length += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (length);
}
