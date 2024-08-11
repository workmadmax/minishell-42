/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:43:04 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 01:20:35 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	init_work_dir(t_data *data)
{
	char	buff[BUFFER_SIZE];
	char	*current_dir;

	current_dir = getcwd(buff, BUFFER_SIZE);
	if (current_dir == NULL)
		return (false);
	data->work_dir = ft_strdup(current_dir);
	if (data->work_dir == NULL)
		return (false);
	return (true);
}

static bool	init_old_dir(t_data *data)
{
	char	*old_dir_env;

	old_dir_env = get_env_item(data->env, "OLDPWD");
	if (old_dir_env != NULL)
	{
		data->old_dir = ft_strdup(old_dir_env);
		if (data->old_dir == NULL)
			return (false);
	}
	else
	{
		data->old_dir = ft_strdup(data->work_dir);
		if (data->old_dir == NULL)
			return (false);
	}
	return (true);
}

static bool	init_words(t_data *data)
{
	if (!init_work_dir(data))
		return (false);
	if (!init_old_dir(data))
	{
		ft_free_string(&data->work_dir);
		return (false);
	}
	return (true);
}

bool	init_data(t_data *data, char **env)
{
	if (!init_env(data, env))
	{
		error_cmd_msg("Error: malloc failed", NULL, NULL, 1);
		return (false);
	}
	if (!init_words(data))
	{
		error_cmd_msg("Error: malloc failed", NULL, NULL, 1);
		return (false);
	}
	data->cmd = NULL;
	data->user_input = NULL;
	data->token = NULL;
	data->pid = -1;
	data->exit_code = 0;
	return (true);
}
