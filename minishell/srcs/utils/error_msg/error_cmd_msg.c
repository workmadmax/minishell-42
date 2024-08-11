/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:37:11 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:05:48 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	add_details(char *command)
{
	if (ft_strncmp(command, "export", 7) == 0
		|| ft_strncmp(command, "unset", 6) == 0)
		return (true);
	return (false);
}

int	error_cmd_msg(char *command, char *detail, char *error_msg, int error_code)
{
	char	*msg;
	bool	detail_flag;

	detail_flag = add_details(command);
	msg = ft_strdup("minishell: ");
	if (command != NULL)
	{
		msg = append_string(msg, command);
		msg = append_string(msg, ": ");
	}
	if (detail != NULL)
	{
		if (detail_flag)
			msg = append_string(msg, "`");
		msg = append_string(msg, detail);
		if (detail_flag)
			msg = append_string(msg, "'");
		msg = append_string(msg, ": ");
	}
	msg = append_string(msg, error_msg);
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_free_ptr(msg);
	return (error_code);
}
