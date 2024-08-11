/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:46:53 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 20:17:41 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_command(t_data *data, t_cmd *cmd)
{
	int	status;

	if (ft_strchr(cmd->command, '/') == NULL
		&& get_env_item(data->env, "PATH") != NULL)
	{
		error_cmd_msg(cmd->command, NULL, "command not found", 127);
		return (127);
	}
	status = check_access(cmd);
	if (status != EXIT_SUCCESS)
		return (status);
	status = check_cmd(cmd);
	if (status != EXIT_SUCCESS)
		return (status);
	return (EXIT_SUCCESS);
}

static int	exec_sys_bin(t_data *data, t_cmd *cmd)
{
	if (!cmd->command || cmd->command[0] == '\0')
		return (127);
	if (check_cmd_is_dir(cmd->command))
		return (127);
	cmd->path = get_cmd_path(data, cmd->command);
	if (!cmd->path)
		return (127);
	if (execve(cmd->path, cmd->args, ht_to_array(data->env)) == -1)
		error_cmd_msg("error: exec", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

static int	exec_local_bin(t_data *data, t_cmd *command)
{
	int	status;

	status = check_command(data, command);
	if (status != 0)
		return (status);
	if (execve(command->command, command->args, ht_to_array(data->env)) == -1)
		return (error_cmd_msg("error execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

int	exec_command(t_data *data, t_cmd *command)
{
	int	status;

	if (!command || !command->command)
		close_data(data, error_cmd_msg("child", NULL,
				"an unexpected error has occurred", EXIT_FAILURE));
	if (!check_io(command->redir))
		close_data(data, EXIT_FAILURE);
	setup_pipes(data->cmd, command);
	redirect_io(command->redir);
	close_fd(data->cmd, false);
	if (ft_strchr(command->command, '/') == NULL)
	{
		status = exec_builtin(data, command);
		if (status != 127)
			close_data(data, status);
		status = exec_sys_bin(data, command);
		if (status != 127)
			close_data(data, status);
	}
	status = exec_local_bin(data, command);
	close_data(data, status);
	return (status);
}
