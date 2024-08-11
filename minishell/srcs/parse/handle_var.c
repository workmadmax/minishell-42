/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:06:43 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/31 18:29:12 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	handle_var(t_data *data)
{
	t_token	*token;

	token = data->token;
	if (!token)
		return (false);
	while (token->type != END)
	{
		if (token->type == VAR && check_quotes(token->input) != SINGLE_QUOTES)
			token->input = expand_var(data, token);
		token = token->next;
	}
	return (true);
}
