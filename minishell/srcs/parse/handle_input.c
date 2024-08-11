/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:18:38 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:53:55 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	remove_old_reference(t_redir *io_fds, bool infile)
{
	if (infile == true && io_fds->file_in)
	{
		if (io_fds->fd_in == -1 || (io_fds->file_out && io_fds->fd_out == -1))
			return (false);
		if (io_fds->heredoc_delim != NULL)
		{
			ft_free_ptr(io_fds->heredoc_delim);
			io_fds->heredoc_delim = NULL;
			unlink(io_fds->file_in);
		}
		ft_free_ptr(io_fds->file_in);
		close(io_fds->fd_in);
	}
	else if (infile == false && io_fds->file_out)
	{
		if (io_fds->fd_out == -1 || (io_fds->file_in && io_fds->fd_in == -1))
			return (false);
		ft_free_ptr(io_fds->file_out);
		close(io_fds->fd_out);
	}
	return (true);
}

static void	open_infile(t_redir *io_fds, char *file, char *filename)
{
	if (!remove_old_reference(io_fds, true))
		return ;
	io_fds->file_in = ft_strdup(file);
	if (io_fds->file_in && io_fds->file_in[0] == '\0')
	{
		error_cmd_msg(filename, NULL, "ambiguous redirect", false);
		return ;
	}
	io_fds->fd_in = open(io_fds->file_in, O_RDONLY);
	if (io_fds->fd_in == -1)
	{
		io_fds->fd_in_error = true;
		error_cmd_msg(io_fds->file_in, NULL, strerror(errno), false);
	}
}

void	handle_input(t_cmd **last_cmd, t_token **token_list)
{
	t_token	*temp;
	t_cmd	*cmd;

	temp = *token_list;
	cmd = add_last_cmd(*last_cmd);
	init_io_fds(cmd);
	open_infile(cmd->redir, temp->next->input, temp->next->backup);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_list = temp;
}
