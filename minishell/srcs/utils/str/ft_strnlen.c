/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:05:05 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:09:43 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && len < max)
		len++;
	return (len);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*new_str;
	size_t	len;

	len = ft_strnlen(str, n);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (0);
	new_str[len] = '\0';
	return ((char *)ft_memcpy(new_str, str, len));
}
