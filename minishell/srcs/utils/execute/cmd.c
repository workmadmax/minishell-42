/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:18:04 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 20:42:45 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

int	check_cmd(t_cmd *cmd)
{
	if (check_cmd_is_dir(cmd->command))
	{
		error_cmd_msg(cmd->command, NULL, "Is a directory", 126);
		return (126);
	}
	return (EXIT_SUCCESS);
}

int	check_access(t_cmd *cmd)
{
	if (access(cmd->command, F_OK | X_OK) != 0)
	{
		if (errno == EACCES)
		{
			error_cmd_msg(cmd->command, NULL, "Permission denied", 126);
			return (126);
		}
		else
		{
			error_cmd_msg(cmd->command, NULL, strerror(errno), errno);
			return (127);
		}
	}
	return (EXIT_SUCCESS);
}
