/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:58:41 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/31 09:01:07 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_exit(void)
{
	printf("\n\n%s====================\n", GREEN);
	printf("%sExited with success!\n", RESET_COLORS);
	printf("%s====================\n\n%s", GREEN, RESET_COLORS);
}

void	close_data(t_data *data, int exno)
{
	if (data)
	{
		if (data->cmd && data->cmd->redir)
			close_fd(data->cmd, true);
		free_data(data, true);
	}
	exit (exno);
}

void	close_fd(t_cmd *cmd_list, bool free_fd)
{
	if (cmd_list->redir)
	{
		if (cmd_list->redir->fd_in != -1)
			close(cmd_list->redir->fd_in);
		if (cmd_list->redir->fd_out != -1)
			close(cmd_list->redir->fd_out);
		if (free_fd)
			reset_io(cmd_list->redir);
	}
	close_pipes_fd(cmd_list, NULL);
}
