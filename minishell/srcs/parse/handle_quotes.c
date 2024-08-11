/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:30:01 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/29 04:19:34 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *input)
{
	int	index;

	index = 0;
	while (input[index])
	{
		if (input[index] == '\'')
			return (SINGLE_QUOTES);
		else if (input[index] == '\"')
			return (DOUBLE_QUOTES);
		index++;
	}
	return (DEFAULT);
}

int	count_size(char *input, int count, int index)
{
	int	status;

	status = 0;
	while (input[index])
	{
		if ((input[index] == '\'' || input[index] == '\"') && status == DEFAULT)
		{
			if (input[index] == '\'')
				status = SINGLE_QUOTES;
			else
				status = DOUBLE_QUOTES;
			index++;
		}
		else if ((input[index] == '\'' && status == SINGLE_QUOTES)
			|| (input[index] == '\"' && status == DOUBLE_QUOTES))
		{
			status = DEFAULT;
			index++;
			continue ;
		}
		count++;
		index++;
	}
	return (count + 1);
}

int	handle_quotes(t_data *data)
{
	t_token	*temp;

	temp = data->token;
	while (temp)
	{
		if (check_quotes(temp->input) > DEFAULT
			&& (!temp->prev || (temp->prev && temp->prev->type != HEREDOC)))
			remove_quotes(&temp);
		temp = temp->next;
	}
	return (0);
}
