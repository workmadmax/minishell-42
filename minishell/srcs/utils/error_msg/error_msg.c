/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:17:57 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:05:13 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*append_string(char *string, char *add)
{
	char	*temp;

	if (!add)
		return (string);
	if (!string)
		return (ft_strdup(add));
	temp = string;
	string = ft_strjoin(string, add);
	ft_free_ptr(temp);
	return (string);
}

void	error_msg(char *error_msg, char *detail, int quotes)
{
	char	*temp;

	temp = ft_strdup("minishell:");
	temp = append_string(temp, error_msg);
	if (quotes)
		temp = append_string(temp, " `");
	else
		temp = append_string(temp, ": ");
	temp = append_string(temp, detail);
	if (quotes)
		temp = append_string(temp, "'");
	ft_putendl_fd(temp, STDERR_FILENO);
	free(temp);
}
