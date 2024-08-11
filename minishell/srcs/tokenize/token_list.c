/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:44:22 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:03:22 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_back_token(t_token **token_list, t_token *new_token)
{
	t_token	*last;

	last = *token_list;
	if (last == NULL)
	{
		*token_list = new_token;
		return ;
	}
	if (token_list && *token_list && new_token)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_token;
		new_token->prev = last;
	}
}

t_token	*add_new_token(char *input, char *input_bkp, int type, int status)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token) * 1);
	if (!new_token)
		return (NULL);
	new_token->input = input;
	new_token->backup = input_bkp;
	new_token->var_status = false;
	new_token->type = type;
	new_token->status = status;
	new_token->join = false;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

static void	append_token_list(t_token *del_token,
	t_token *temp, t_token *insert)
{
	while (temp != del_token)
		temp = temp->next;
	insert->prev = temp->prev;
	temp->prev->next = insert;
	while (insert->next)
		insert = insert->next;
	temp->next->prev = insert;
	insert->next = temp->next;
}

t_token	*insert_list_between(t_token **head,
	t_token *del_token, t_token *insert)
{
	t_token	*temp;

	temp = *head;
	if (temp == NULL)
		*head = insert;
	else if (temp == del_token)
	{
		*head = insert;
		insert->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = insert;
	}
	else
		append_token_list(del_token, temp, insert);
	ft_free_ptr(del_token->input);
	ft_free_ptr(del_token);
	return (insert);
}
