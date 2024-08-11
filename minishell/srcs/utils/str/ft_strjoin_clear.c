/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:09:48 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/31 07:17:04 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_clear(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

char	*ft_concat_sub(char *src, char *input, int start, int len)
{
	char	*res;
	char	*temp;

	if (len > 0)
		temp = ft_substr(input, start, len);
	else
		temp = ft_calloc(1, 1);
	res = ft_strjoin_clear(src, temp);
	return (res);
}
