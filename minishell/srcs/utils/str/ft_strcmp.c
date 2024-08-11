/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:24:56 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/14 15:13:43 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_space(char c)
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

int	ft_strcmp(const char *str1, const char *str2)
{
	int	index;

	index = 0;
	while (str1[index] == str2[index] && str1[index] != '\0')
		index++;
	if (str1[index] > str2[index])
		return (str1[index] - str2[index]);
	else if (str1[index] < str2[index])
		return (str1[index] - str2[index]);
	return (0);
}
