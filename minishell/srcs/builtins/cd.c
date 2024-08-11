/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:48 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/01 23:40:41 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(t_data *data)
{
	if (!data->cmd->args[1])
	{
		chdir(get_env_item(data->env, "HOME"));
		update_pwd_env(data->env);
		return (EXIT_SUCCESS);
	}
	if (data->cmd->args[2])
	{
		error_cmd_msg("cd", NULL, "too many arguments", 1);
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(data->cmd->args[1], "-") == 0)
		return (cd_oldpwd(data));
	if (ft_strcmp(data->cmd->args[1], ".") == 0)
		return (cd_pwd(data));
	if (ft_strcmp(data->cmd->args[1], "..") == 0)
		return (cd_parent_dir(data));
	return (cd_dir(data));
}
