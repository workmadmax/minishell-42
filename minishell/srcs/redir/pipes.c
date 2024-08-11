/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:51:28 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:59:12 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes_fd(t_cmd *cmd_list, t_cmd *skip)
{
	while (cmd_list)
	{
		if (cmd_list != skip && cmd_list->pipe_fd)
		{
			close(cmd_list->pipe_fd[0]);
			close(cmd_list->pipe_fd[1]);
		}
		cmd_list = cmd_list->next;
	}
}

bool	setup_pipes(t_cmd *cmd_list, t_cmd *cmd)
{
	if (!cmd)
		return (false);
	if (cmd->prev && cmd->prev->pipe_out)
		dup2(cmd->prev->pipe_fd[0], STDIN_FILENO);
	if (cmd->pipe_out)
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
	close_pipes_fd(cmd_list, cmd);
	return (true);
}

bool	create_pipes(t_data *data)
{
	int		*fd;
	t_cmd	*temp;

	temp = data->cmd;
	while (temp)
	{
		if (temp->pipe_out || (temp->prev && temp->prev->pipe_out))
		{
			fd = malloc(sizeof * fd * 2);
			if (!fd || pipe(fd) != 0)
			{
				free_data(data, false);
				return (false);
			}
			temp->pipe_fd = fd;
		}
		temp = temp->next;
	}
	return (true);
}
