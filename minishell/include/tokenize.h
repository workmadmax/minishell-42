/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:07:24 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/13 20:46:21 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "minishell.h"

/* checkers */

int		check_operator(t_token **token_list);
int		check_if_variable(t_token **token_list);

/* list token */

void	clear_list_token(t_token **token_list, void (*del)(void *));
void	del_token(t_token *token_list, void (*del)(void *));
void	add_back_token(t_token **token_list, t_token *new_token);
t_token	*add_new_token(char *input, char *input_bkp, int type, int status);
t_token	*insert_list_between(t_token **head, t_token *del_token,
			t_token *insert);

/* token utils */

int		set_status(int status, char *input, int index);
int		handle_separator(char *input, int index);
int		save_separator(t_token **token_list, char *input, int index, int type);
// int     save_word(t_token **token_list, char *input, int index, int start);
int		save_word(t_data *data, char *input, int index, int start);
int		save_word_sep(t_data *data, char *input, int *index, int start);

/* tokenize */

int		tokenize(t_data *data, char *input);
bool	handle_user_input(t_data *data);

#endif