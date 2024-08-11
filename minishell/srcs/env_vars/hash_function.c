/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:27 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/24 11:50:14 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	hash_function(char *key)
{
	size_t	hash;
	size_t	i;

	hash = 0;
	i = 0;
	while (i < ft_strlen(key))
	{
		hash += key[i] / 3;
		i++;
	}
	while (hash > ENVCAPACITY)
		hash /= 3;
	return (hash);
}
