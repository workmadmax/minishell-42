/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:17:27 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/31 07:14:32 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

/* parse command */

t_cmd	*add_last_cmd(t_cmd *command_list);
t_cmd	*add_new_cmd(bool value);
void	add_back_cmd(t_cmd **command_list, t_cmd *new_cmd);
void	create_cmd_list(t_data *data, t_token *token_list);
void	clear_cmd_list(t_cmd **command_list, void (*del)(void *));
void	list_delone_cmd(t_cmd *command_list, void (*del)(void *));

/* parse append */

void	handle_append(t_cmd **last_cmd, t_token **token_list);

/* parse argumenst */

int		create_args_default(t_token **current_token, t_cmd *last_cmd);
int		append_args(t_token **current_token, t_cmd *last_cmd);
int		handle_args_default(t_token **current_token, t_cmd *last_cmd);
int		create_args_echo(t_token **current_token, t_cmd *last_cmd);
int		append_args_echo(t_token **current_token, t_cmd *last_cmd);

/* parse utils */

int		count_arguments(t_token *temp);
int		count_joined_arguments(t_token *temp);
char	*append_vars(t_token **current_token);
void	remove_empty(t_token **current_token);
char	**copy_echo(t_cmd *last_cmd, t_token *temp, char **new_tab, int size);

/* parse heredoc */

void	handle_heredoc(t_data *data, t_cmd **last_cmd, t_token **token_list);

/* parse input */

bool	remove_old_reference(t_redir *io_fds, bool infile);
void	handle_input(t_cmd **last_cmd, t_token **token_list);

/* parse pipe */

void	handle_pipe(t_cmd **cmd, t_token **token_list);

/* parse trunc */

void	handle_trunc(t_cmd **last_cmd, t_token **token_list);

/* parse word */

void	handle_word(t_cmd **cmd, t_token **token_list);

/* parse quotes */

int		check_quotes(char *input);
int		count_size(char *input, int count, int index);
int		handle_quotes(t_data *data);

/* handle env vars */

bool	handle_var(t_data *data);

#endif
