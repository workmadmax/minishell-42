/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:04:34 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/13 23:27:54 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

bool	check_cmd_is_dir(char *cmd);
int		check_command(t_data *data, t_cmd *cmd);
int		exec_command(t_data *data, t_cmd *command);

/* exec path command */

char	*find_path_cmd(char *cmd, char **path);
char	**find_path_env(t_data *data);
char	*get_cmd_path(t_data *data, char *name);

/* exec proc */

int		exec_proc(t_data *data);

void	minishell(t_data *data);

/* exec builtins */

int		exec_builtin(t_data *data, t_cmd *cmd);

#endif