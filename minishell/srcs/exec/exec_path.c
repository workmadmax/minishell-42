/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:19:33 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:47:18 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_cmd(char *cmd, char **path)
{
	int		index;
	char	*path_cmd;

	index = 0;
	path_cmd = NULL;
	while (path[index])
	{
		path_cmd = ft_strjoin(path[index], cmd);
		if (!path_cmd)
		{
			error_cmd_msg("malloc", NULL, "an unexpected error has occurred",
				EXIT_FAILURE);
			return (NULL);
		}
		if (access(path_cmd, F_OK | X_OK) == 0)
			return (path_cmd);
		ft_free_ptr(path_cmd);
		index++;
	}
	return (NULL);
}

char	**find_path_env(t_data *data)
{
	char	*path_value;
	char	**path_env;

	path_value = NULL;
	path_value = get_env_item(data->env, "PATH");
	if (!path_value)
		return (NULL);
	path_env = ft_split(path_value, ':');
	if (!path_env)
	{
		free(path_value);
		return (NULL);
	}
	return (path_env);
}

char	*get_cmd_path(t_data *data, char *name)
{
	char	**path_env;
	char	*path_cmd;
	char	*command;

	if (!name)
		return (NULL);
	path_env = find_path_env(data);
	if (!path_env)
		return (NULL);
	command = ft_strjoin("/", name);
	if (!command)
	{
		ft_free_string(path_env);
		return (NULL);
	}
	path_cmd = find_path_cmd(command, path_env);
	if (!path_cmd)
	{
		ft_free_ptr(command);
		ft_free_string(path_env);
		return (NULL);
	}
	return (path_cmd);
}
