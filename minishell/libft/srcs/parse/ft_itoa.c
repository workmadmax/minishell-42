/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:42:09 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:39:47 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_count_digit(int nbr)
{
	int	index;

	index = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		index++;
	}
	return (index);
}

static	char	*helper(int nbr, char *string, size_t length)
{
	if (nbr == 0)
		string[0] = '0';
	else if (length == 1)
		string[0] = '-';
	return (string);
}
/**
 * @brief Converts an integer to a string.
 * 
 * @param nbr The integer to be converted.
 * @return char* Pointer to the resulting
 * string. Returns NULL if memory allocation
 * fails.
 */

char	*ft_itoa(int nbr)
{
	char		*string;
	size_t		length;
	long int	num;

	num = nbr;
	length = 0;
	if (num < 0)
	{
		num = num * -1;
		length = 1;
	}
	length = length + ft_count_digit(nbr);
	string = malloc((length + 1));
	if (string == 0)
		return (0);
	string[length] = '\0';
	while (num > 0)
	{
		string[length - 1] = num % 10 + '0';
		num = num / 10;
		length--;
	}
	return (helper(nbr, string, length));
}
