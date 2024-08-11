/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:25:37 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 02:10:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static bool	check_max_min(long long int *result, int sign, int digit, int base)
{
	if (sign == 1 && digit > LLONG_MAX % base)
	{
		*result = LLONG_MAX;
		return (true);
	}
	else if (sign == -1 && digit > (LLONG_MAX % base) + 1)
	{
		*result = LLONG_MIN;
		return (true);
	}
	return (false);
}

long long int	ft_strtoll(const char *str, char **endptr, int base)
{
	int				digit;
	long long int	result;
	int				sign;

	result = 0;
	sign = get_sign(&str);
	while (*str != '\0')
	{
		digit = *str - '0';
		if (digit >= base)
			break ;
		if (result == LLONG_MAX / base)
		{
			if (check_max_min(&result, sign, digit, base))
				break ;
		}
		result = result * base + digit;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * sign);
}
