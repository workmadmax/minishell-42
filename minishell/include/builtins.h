/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:28:13 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 00:26:51 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		cd(t_data *data);
int		echo(char **args);
void	print_envvars(t_hashtable *env_table);
void	print_exportvars(t_hashtable *env_table);
int		env(t_hashtable *ht, char **args);
int		ft_export(t_hashtable *ht, char *input);
int		pwd(void);
int		unset(t_hashtable *ht, char *input);
int		ft_exit(t_data *data, char **args);

#endif