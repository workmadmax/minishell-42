/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:58:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/01 23:47:35 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_data *data, t_cmd *cmd)
{
	int	status;

	if (ft_strncmp(cmd->command, "cd", 2) == 0)
		status = cd(data);
	else if (ft_strncmp(cmd->command, "echo", 4) == 0)
		status = echo(cmd->args);
	else if (ft_strncmp(cmd->command, "env", 3) == 0)
		status = env(data->env, cmd->args);
	else if (ft_strncmp(cmd->command, "export", 6) == 0)
		status = ft_export(data->env, cmd->args[1]);
	else if (ft_strncmp(cmd->command, "pwd", 3) == 0)
		status = pwd();
	else if (ft_strncmp(cmd->command, "unset", 5) == 0)
		status = unset(data->env, cmd->args[1]);
	else if (ft_strncmp(cmd->command, "exit", 4) == 0)
		status = ft_exit(data, cmd->args);
	else
		return (127);
	return (status);
}
