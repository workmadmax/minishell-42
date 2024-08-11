/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:35:54 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 02:13:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_status(int status, char *input, int index)
{
	if (input[index] == '\'' && status == DEFAULT)
		status = SINGLE_QUOTES;
	else if (input[index] == '\"' && status == DEFAULT)
		status = DOUBLE_QUOTES;
	else if (input[index] == '\'' && status == SINGLE_QUOTES)
		status = DEFAULT;
	else if (input[index] == '\"' && status == DOUBLE_QUOTES)
		status = DEFAULT;
	return (status);
}

int	handle_separator(char *input, int index)
{
	if (((input[index] > 8 && input[index] < 14) || input[index] == 32))
		return (SPACES);
	else if (input[index] == '|')
		return (PIPE);
	else if (input[index] == '<' && input[index + 1] == '<')
		return (HEREDOC);
	else if (input[index] == '>' && input[index + 1] == '>')
		return (APPEND);
	else if (input[index] == '<')
		return (INPUT);
	else if (input[index] == '>')
		return (TRUNC);
	else if (input[index] == '\0')
		return (END);
	else
		return (0);
}

int	save_separator(t_token **token_list, char *input, int index, int type)
{
	int		count;
	char	*sep;

	count = 0;
	if (type == APPEND || type == HEREDOC)
	{
		sep = malloc(sizeof(char) * 3);
		if (!sep)
			return (1);
		while (count < 2)
			sep[count++] = input[index++];
		sep[count] = '\0';
		add_back_token(token_list, add_new_token(sep, NULL, type, DEFAULT));
	}
	else
	{
		sep = malloc(sizeof(char) * 2);
		if (!sep)
			return (1);
		while (count < 1)
			sep[count++] = input[index++];
		sep[count] = '\0';
		add_back_token(token_list, add_new_token(sep, NULL, type, DEFAULT));
	}
	return (0);
}

int	save_word(t_data *data, char *input, int index, int start)
{
	int		end;
	char	*word;

	end = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (1);
	while (start < index)
	{
		word[end] = input[start];
		start++;
		end++;
	}
	word[end] = '\0';
	add_back_token(&data->token, add_new_token(word,
			ft_strdup(word), WORD, DEFAULT));
	return (0);
}

int	save_word_sep(t_data *data, char *input, int *index, int start)
{
	int	type;

	type = handle_separator(input, (*index));
	if (type)
	{
		if ((*index) != 0 && handle_separator(input, (*index) - 1) == 0)
			save_word(data, input, (*index), start);
		if (type == APPEND || type == HEREDOC || type == PIPE || type == INPUT
			|| type == TRUNC || type == END)
		{
			save_separator(&data->token, input, (*index), type);
			if (type == APPEND || type == HEREDOC)
				(*index)++;
		}
		start = (*index) + 1;
	}
	return (start);
}
