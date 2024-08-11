/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:54:44 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:00:47 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_token(t_token *token_list, void (*del)(void *))
{
	if (del && token_list && token_list->input)
	{
		(*del)(token_list->input);
		token_list->input = NULL;
	}
	if (del && token_list && token_list->backup)
	{
		(*del)(token_list->backup);
		token_list->backup = NULL;
	}
	if (token_list->prev)
		token_list->prev->next = token_list->next;
	if (token_list->next)
		token_list->next->prev = token_list->prev;
	ft_free_ptr(token_list);
}

void	clear_list_token(t_token **token_list, void (*del)(void *))
{
	t_token	*temp;

	temp = NULL;
	while (*token_list != NULL)
	{
		temp = (*token_list)->next;
		del_token(*token_list, del);
		*token_list = temp;
	}
}
