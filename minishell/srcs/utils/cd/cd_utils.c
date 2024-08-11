/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:38:05 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/28 13:38:12 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_parent_dir(t_data *data)
{
	char	*current_path;
	char	*last_slash;

	current_path = getcwd(NULL, 0);
	last_slash = ft_strrchr(current_path, '/');
	if (!last_slash)
	{
		ft_free_ptr(current_path);
		error_cmd_msg("Error getting parent directory", NULL, NULL, 1);
		return (EXIT_FAILURE);
	}
	*last_slash = '\0';
	chdir(current_path);
	ht_add_update_items(data->env, "OLDPWD", get_env_item(data->env, "PWD"));
	update_pwd_env(data->env);
	ft_free_ptr(current_path);
	return (EXIT_SUCCESS);
}

int	cd_dir_change(t_data *data, char *new_path)
{
	char	*old_path;
	char	*pwd;

	old_path = get_env_item(data->env, "PWD");
	pwd = getcwd(NULL, 0);
	if (chdir(new_path) == -1)
	{
		error_cmd_msg("Permission denied", NULL, NULL, true);
		ft_free_ptr(pwd);
		ft_free_ptr(old_path);
		return (EXIT_FAILURE);
	}
	ht_add_update_items(data->env, "OLDPWD", old_path);
	update_pwd_env(data->env);
	ft_free_ptr(pwd);
	return (EXIT_SUCCESS);
}

int	cd_dir(t_data *data)
{
	int		ret;
	char	*new_path;

	new_path = ft_strdup(data->cmd->args[1]);
	ret = cd_dir_check(new_path);
	if (ret != EXIT_SUCCESS)
	{
		ft_free_ptr(new_path);
		return (ret);
	}
	ret = cd_dir_change(data, new_path);
	ft_free_ptr(new_path);
	return (ret);
}
