/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:15:43 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:04:11 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_dir_check(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == -1)
	{
		error_cmd_msg("cd", path, "No such file or directory", true);
		return (EXIT_FAILURE);
	}
	if (!S_ISDIR(path_stat.st_mode))
	{
		error_cmd_msg("Not a directory", NULL, NULL, true);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	cd_oldpwd(t_data *data)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = get_env_item(data->env, "OLDPWD");
	if (oldpwd == NULL)
	{
		error_cmd_msg("OLDPWD not set", NULL, NULL, 1);
		return (EXIT_FAILURE);
	}
	pwd = getcwd(NULL, 0);
	if (chdir(oldpwd) == -1)
	{
		error_cmd_msg("Permission denied", NULL, NULL, 1);
		ft_free_ptr(pwd);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd(oldpwd, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ht_add_update_items(data->env, "OLDPWD", pwd);
	update_pwd_env(data->env);
	ft_free_ptr(pwd);
	return (EXIT_SUCCESS);
}

int	cd_pwd(t_data *data)
{
	chdir(get_env_item(data->env, "PWD"));
	update_pwd_env(data->env);
	return (EXIT_SUCCESS);
}

void	update_pwd_env(t_hashtable *env)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		ht_add_update_items(env, "OLDPWD", get_env_item(env, "PWD"));
		ht_add_update_items(env, "PWD", cwd);
		ft_free_ptr(cwd);
	}
}
