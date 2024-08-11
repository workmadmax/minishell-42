/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:14:37 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 00:37:46 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_trim_start(char *str, size_t n)
{
	size_t	i;
	size_t	len;
	char	*str_trimmed;

	if (!n || !str)
		return ("");
	i = 0;
	len = ft_strlen(str);
	str_trimmed = malloc(sizeof(char) * (len - n + 1));
	while (n < len)
		str_trimmed[i++] = str[n++];
	str_trimmed[i] = '\0';
	return (str_trimmed);
}

static int	find_sep_pos(char *str, char sep)
{
	size_t	pos;

	pos = 0;
	while (str[pos] != sep && str[pos] != '\0')
		pos++;
	return (pos);
}

char	**str_split_in_two(char *str, char sep)
{
	size_t	pos;
	char	**res;

	pos = find_sep_pos(str, sep);
	if (!str || !sep)
		return (NULL);
	if (pos >= ft_strlen(str))
		return (NULL);
	res = ft_calloc(3, sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = ft_substr(str, 0, pos);
	if (!res[0])
	{
		free(res);
		return (NULL);
	}
	res[1] = ft_substr(str, pos + 1, ft_strlen(str));
	if (!res[1])
	{
		free(res[0]);
		free(res);
		return (NULL);
	}
	return (res);
}
