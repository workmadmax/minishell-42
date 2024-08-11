/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:29:46 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:37:56 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_check_space(char c)
{
	if (c == '\t'
		|| c == '\v'
		|| c == '\r'
		|| c == '\n'
		|| c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}
/**
 * @brief Converts the string argument 'str'
 * to an integer (type int).
 * 
 * @param string This is the string representation
 * of an integral number.
 * @return This function returns the converted
 * integral number as an int value.
 * If no valid conversion could be performed,
 * it returns zero.
*/

int	ft_atoi(const char *string)
{
	int	result;
	int	negative;

	negative = 0;
	result = 0;
	while (ft_check_space(*string))
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			negative = 1;
		string++;
	}
	while (ft_isdigit(*string))
		result = (result * 10) + (*string++ -48);
	if (negative)
		return (result * -1);
	return (result);
}
