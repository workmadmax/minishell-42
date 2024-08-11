/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:32:17 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:55:40 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	open_outfile_append(t_redir *io_fds, char *file, char *filename)
{
	if (!remove_old_reference(io_fds, false))
		return ;
	io_fds->file_out = ft_strdup(file);
	if (io_fds->file_out && io_fds->file_out[0] == '\0' && filename)
	{
		error_cmd_msg(filename, NULL, "ambiguous redirect", false);
		return ;
	}
	io_fds->fd_out = open(io_fds->file_out,
			O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (io_fds->fd_out == -1)
		error_cmd_msg(io_fds->file_out, NULL, strerror(errno), false);
}

void	handle_append(t_cmd **last_cmd, t_token **token_list)
{
	t_cmd	*cmd;
	t_token	*temp;

	temp = *token_list;
	cmd = add_last_cmd(*last_cmd);
	init_io_fds(cmd);
	open_outfile_append(cmd->redir, temp->next->input, temp->next->backup);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_list = temp;
}
