/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:39:42 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:46:49 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wait_child(t_data *data)
{
	int		status;
	int		save_status;
	pid_t	pid;

	close_fd(data->cmd, false);
	save_status = 0;
	pid = 0;
	while (pid != -1 || errno != ECHILD)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == data->pid)
			save_status = status;
		continue ;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	return (status);
}

static int	create_child(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	while (data->pid != 0 && cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (error_cmd_msg("fork", NULL, strerror(errno), EXIT_FAILURE));
		else if (data->pid == 0)
			exec_command(data, cmd);
		cmd = cmd->next;
	}
	return (wait_child(data));
}

static int	setup_exec(t_data *data)
{
	if (!data || !data->cmd)
		return (EXIT_FAILURE);
	if (!data->cmd->command)
	{
		if (data->cmd->redir && !check_io(data->cmd->redir))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (!create_pipes(data))
		return (EXIT_FAILURE);
	return (127);
}

int	exec_proc(t_data *data)
{
	int	status;

	status = setup_exec(data);
	if (status != 127)
		return (status);
	if (!data->cmd->pipe_out && !data->cmd->prev && check_io(data->cmd->redir))
	{
		redirect_io(data->cmd->redir);
		status = exec_builtin(data, data->cmd);
		reset_io(data->cmd->redir);
	}
	if (status != 127)
		return (status);
	return (create_child(data));
}
