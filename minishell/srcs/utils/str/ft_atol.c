/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:25:37 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/31 10:26:44 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long	ft_is_neg(int number, long nbr)
{
	if (number % 2 == 1)
		nbr *= -1;
	return (nbr);
}

long long int	ft_atol(const char *str)
{
	long long int	nbr;
	int				i;
	int				negative;

	i = 0;
	nbr = 0;
	negative = 0;
	while ((str[i] > 6 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
	{
		negative++;
		i++;
	}
	if (str[i] == '+' && str[i + 1] > 47 && str[i + 1] < 58)
		i++;
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (ft_is_neg(negative, nbr));
}
