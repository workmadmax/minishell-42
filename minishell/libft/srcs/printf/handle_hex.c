/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:08:38 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:43:37 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Processes a hexadecimal number
 * format specifier.
 * 
 * @param x The hexadecimal number to be print.
 * @param prefix Indicates whether ti add the
 * '0x' prefix to the output.
 * @param cap Indicates whether to use capital
 * letters to represent.
 * @return size_t The number of characters print.
 */
size_t	handle_hex(unsigned long x, int prefix, size_t cap)
{
	char	*base;
	size_t	length;

	length = 0;
	if (x == 0 && prefix)
		return (write(1, "(nil)", 5));
	if (prefix)
		length += write(1, "0x", 2);
	if (!cap)
		base = "0123456789abcdef";
	if (cap)
		base = "0123456789ABCDEF";
	if (x > 15)
		length = handle_hex((x / 16), 0, cap);
	length += write(1, &base[x % 16], 1);
	return (length);
}
