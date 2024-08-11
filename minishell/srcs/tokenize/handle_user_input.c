/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:43:48 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 00:01:08 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_is_space(char *input)
{
	int	index;

	index = 0;
	while (input[index])
	{
		if (!ft_check_space(input[index]))
			return (false);
		index++;
	}
	return (true);
}

int	tokenize(t_data *data, char *input)
{
	int	index;
	int	status;
	int	start;
	int	end;

	index = -1;
	start = 0;
	end = ft_strlen(input);
	status = DEFAULT;
	while (++index <= end)
	{
		status = set_status(status, input, index);
		if (status == DEFAULT)
			start = save_word_sep(data, input, &index, start);
	}
	if (status != DEFAULT)
	{
		if (status == DOUBLE_QUOTES)
			error_msg("Unmatched", "double quotes", true);
		else if (status == SINGLE_QUOTES)
			error_msg("Unmatched", "single quotes", true);
		error_msg("syntax error near unexpected token", input, false);
		return (1);
	}
	return (0);
}

bool	handle_user_input(t_data *data)
{
	if (ft_strcmp(data->user_input, "\0") == 0)
		return (false);
	add_history(data->user_input);
	if (check_is_space(data->user_input))
		return (false);
	if (tokenize(data, data->user_input) == FAILURE)
		return (false);
	if (data->token->type == END)
		return (false);
	if (check_if_variable(&data->token) == FAILURE)
		return (false);
	if (!handle_var(data))
		return (false);
	handle_quotes(data);
	create_cmd_list(data, data->token);
	return (true);
}
