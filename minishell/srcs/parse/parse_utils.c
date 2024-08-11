/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:52:12 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:56:09 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_arguments(t_token *temp)
{
	int	count;

	count = 0;
	while (temp && (temp->type == WORD || temp->type == VAR))
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	count_joined_arguments(t_token *temp)
{
	int	index;

	index = 0;
	while (temp && (temp->type == WORD || temp->type == VAR))
	{
		if (temp->type == VAR && temp->join == true)
		{
			while (temp->type == VAR && temp->join == true)
				temp = temp->next;
			index++;
		}
		else
		{
			index++;
			temp = temp->next;
		}
	}
	return (index);
}

char	*append_vars(t_token **current_token)
{
	char	*input;
	t_token	*temp;

	temp = *current_token;
	input = ft_strdup(temp->input);
	while (temp->type == VAR && temp->next->type == VAR
		&& temp->next->join == true)
	{
		input = ft_strjoin(input, temp->next->input);
		temp = temp->next;
	}
	*current_token = temp;
	return (input);
}

void	remove_empty(t_token **current_token)
{
	t_token	*temp;

	temp = *current_token;
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->type == VAR && temp->input[0] == '\0'
			&& temp->var_status == false)
		{
			temp = temp->next;
			if (temp == (*current_token)->next)
				(*current_token) = (*current_token)->next;
			del_token(temp->prev, ft_free_ptr);
		}
		else
			temp = temp->next;
	}
}

char	**copy_echo(t_cmd *last_cmd, t_token *temp, char **new_tab, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		new_tab[index] = last_cmd->args[index];
		index++;
	}
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->join == true)
			new_tab[index] = append_vars(&temp);
		else
			new_tab[index] = ft_strdup(temp->input);
		index++;
		temp = temp->next;
	}
	new_tab[index] = NULL;
	return (new_tab);
}
