/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:44:24 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:57:15 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_space(char *input)
{
	int	index;

	index = 0;
	while (input[index])
	{
		if (input[index] == ' ')
			return (true);
		index++;
	}
	return (false);
}

static void	split_input(t_cmd *last_cmd, char *input_cmd)
{
	int		index;
	char	**words;
	t_token	*temp;
	t_token	*new_token;

	new_token = NULL;
	words = ft_split(input_cmd, ' ');
	if (!words)
		return ;
	last_cmd->command = ft_strdup(words[0]);
	if (words[1])
		new_token = add_new_token(ft_strdup(words[1]), NULL, WORD, DEFAULT);
	temp = new_token;
	index = 1;
	while (words[++index])
		add_back_token(&new_token, add_new_token(ft_strdup(words[index]),
				NULL, WORD, DEFAULT));
	add_back_token(&new_token, add_new_token(NULL, NULL, END, DEFAULT));
	handle_args_default(&new_token, last_cmd);
	clear_list_token(&temp, &ft_free_ptr);
	ft_free_string(words);
}

void	handle_word(t_cmd **cmd, t_token **token_list)
{
	t_cmd	*last_cmd;
	t_token	*temp;

	temp = *token_list;
	while (temp->type == WORD || temp->type == VAR)
	{
		last_cmd = add_last_cmd(*cmd);
		if (temp->prev == NULL || (temp->prev && temp->prev->type == PIPE)
			|| last_cmd->command == NULL)
		{
			if (temp->type == VAR && check_space(temp->input))
				split_input(last_cmd, temp->input);
			else if (ft_strlen(temp->input) == 0 && temp->type == VAR)
				last_cmd->command = NULL;
			else
				last_cmd->command = ft_strdup(temp->input);
			temp = temp->next;
		}
		else
			handle_args_default(&temp, last_cmd);
	}
	*token_list = temp;
}
