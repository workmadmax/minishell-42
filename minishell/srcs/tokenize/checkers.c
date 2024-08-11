/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:07:09 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:02:23 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_variable(t_token **token)
{
	int	index;

	index = 0;
	while ((*token)->input[index])
	{
		if ((*token)->input[index] == '$' || (*token)->input[index] == 126)
		{
			if ((*token)->prev && (*token)->prev->type == HEREDOC)
				break ;
			(*token)->type = VAR;
			return ;
		}
		index++;
	}
}

static bool	check_double_ops(t_token *token)
{
	if (token->prev)
	{
		if (token->type == PIPE && token->prev->type == PIPE)
			return (true);
		if (token->type > PIPE && token->prev->type > PIPE)
			return (true);
		if (token->type == END && token->prev->type >= PIPE)
			return (true);
	}
	return (false);
}

int	check_operator(t_token **token_list)
{
	t_token	*temp;

	temp = *token_list;
	while (temp)
	{
		if (check_double_ops(temp) == true)
		{
			if (temp->type == END && temp->prev && temp->prev->type > PIPE)
				error_msg("syntax error : ", NULL, true);
			else if (temp->type == END && temp->prev)
				error_msg("syntax error : ", temp->prev->input, true);
			else
				error_msg("syntax error : ", temp->input, true);
			return (FAILURE);
		}
		temp = temp->next;
	}
	return (SUCCESS);
}

int	check_if_variable(t_token **token_list)
{
	t_token	*temp;

	temp = *token_list;
	if (temp->type == PIPE)
	{
		error_msg("syntax error : ", temp->input, true);
		return (FAILURE);
	}
	while (temp)
	{
		check_variable(&temp);
		if (check_operator(&temp) == FAILURE)
			return (FAILURE);
		temp = temp->next;
	}
	return (SUCCESS);
}
