/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:39:55 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:59:29 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_io(t_redir *io_fds)
{
	if (!io_fds || (!io_fds->file_in && !io_fds->file_out))
		return (true);
	if ((io_fds->file_in && io_fds->fd_in == -1)
		|| (io_fds->file_out && io_fds->fd_out == -1))
		return (false);
	return (true);
}

bool	reset_io(t_redir *io_fds)
{
	int	status;

	status = true;
	if (!io_fds)
		return (status);
	if (io_fds->stdin_bkp != -1)
	{
		if (dup2(io_fds->stdin_bkp, STDIN_FILENO) == -1)
			status = false;
		close(io_fds->stdin_bkp);
		io_fds->stdin_bkp = -1;
	}
	if (io_fds->stdout_bkp != -1)
	{
		if (dup2(io_fds->stdout_bkp, STDOUT_FILENO) == -1)
			status = false;
		close(io_fds->stdout_bkp);
		io_fds->stdout_bkp = -1;
	}
	return (status);
}

bool	redirect_io(t_redir *io_fds)
{
	int	status;

	status = true;
	if (!io_fds)
		return (status);
	io_fds->stdin_bkp = dup(STDIN_FILENO);
	if (io_fds->stdin_bkp == -1)
		status = error_cmd_msg("dup", "stdin backup", strerror(errno), false);
	io_fds->stdout_bkp = dup(STDOUT_FILENO);
	if (io_fds->stdout_bkp == -1)
		status = error_cmd_msg("dup", "stdout backup", strerror(errno), false);
	if (io_fds->fd_in != -1)
	{
		if (dup2(io_fds->fd_in, STDIN_FILENO) == -1)
			status = error_cmd_msg("dup2", io_fds->file_in,
					strerror(errno), false);
	}
	if (io_fds->fd_out != -1)
	{
		if (dup2(io_fds->fd_out, STDOUT_FILENO) == -1)
			status = error_cmd_msg("dup2", io_fds->file_out,
					strerror(errno), false);
	}
	return (status);
}
