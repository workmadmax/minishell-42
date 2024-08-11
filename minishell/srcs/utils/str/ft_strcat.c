/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:38:59 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/14 15:09:27 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	aux;

	index = 0;
	while (dest[index] != '\0')
		index++;
	aux = 0;
	while (src[aux] != '\0')
	{
		dest[index + aux] = src[aux];
		aux++;
	}
	dest[index + aux] = '\0';
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

char	*ft_strcpy(char *str1, char *str2)
{
	int	index;

	index = 0;
	if (!str2)
		return (NULL);
	while (str2[index] != '\0')
	{
		str1[index] = str2[index];
		index++;
	}
	str1[index] = '\0';
	return (str1);
}
