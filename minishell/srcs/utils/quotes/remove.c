/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:38:25 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:08:56 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_status_quotes(t_token **token, int *index)
{
	if ((*token)->input[*index] == '\'')
		(*token)->status = SINGLE_QUOTES;
	if ((*token)->input[*index] == '\"')
		(*token)->status = DOUBLE_QUOTES;
	(*index)++;
}

static bool	check_default_quotes(t_token **token, int index)
{
	if (((*token)->input[index] == '\'' || (*token)->input[index] == '\"')
		&& (*token)->status == DEFAULT)
		return (true);
	else
		return (false);
}

static bool	reset_status_quotes(t_token **token, int *index)
{
	if (((*token)->input[*index] == '\'' && (*token)->status == SINGLE_QUOTES)
		|| ((*token)->input[*index] == '\"'
			&& (*token)->status == DOUBLE_QUOTES))
	{
		(*token)->status = DEFAULT;
		(*index)++;
		return (true);
	}
	else
		return (false);
}

int	remove_quotes(t_token **token)
{
	int		index;
	int		count;
	char	*new_line;

	index = 0;
	count = 0;
	new_line = malloc(sizeof(char) * count_size((*token)->input, count, index));
	if (!new_line)
		return (1);
	while ((*token)->input[index])
	{
		if (check_default_quotes(token, index) == true)
		{
			set_status_quotes(token, &index);
			continue ;
		}
		else if (reset_status_quotes(token, &index) == true)
			continue ;
		new_line[count++] = (*token)->input[index++];
	}
	new_line[count] = '\0';
	ft_free_ptr((*token)->input);
	(*token)->input = new_line;
	(*token)->join = true;
	return (0);
}
