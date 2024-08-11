/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_cmd_io.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:07:36 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 00:07:43 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_command_list(t_cmd **command_list)
{
	(*command_list)->command = NULL;
	(*command_list)->pipe_out = false;
	(*command_list)->pipe_fd = 0;
	(*command_list)->path = NULL;
	(*command_list)->args = NULL;
	(*command_list)->prev = NULL;
	(*command_list)->next = NULL;
}

void	init_io_fds(t_cmd *cmd_redir)
{
	if (!cmd_redir->redir)
	{
		cmd_redir->redir = malloc(sizeof * cmd_redir->redir);
		if (!cmd_redir->redir)
			return ;
		cmd_redir->redir->file_in = NULL;
		cmd_redir->redir->file_out = NULL;
		cmd_redir->redir->heredoc_delim = NULL;
		cmd_redir->redir->heredoc_quotes = false;
		cmd_redir->redir->fd_in = -1;
		cmd_redir->redir->fd_out = -1;
		cmd_redir->redir->stdin_bkp = -1;
		cmd_redir->redir->stdout_bkp = -1;
		cmd_redir->redir->fd_in_error = false;
	}
}
