/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:34:42 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:53:22 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_args_echo(t_token **current_token, t_cmd *last_cmd)
{
	int		index;
	int		count;
	t_token	*temp;

	remove_empty(current_token);
	temp = *current_token;
	count = count_joined_arguments(temp);
	last_cmd->args = malloc(sizeof(char *) * (count + 2));
	if (!last_cmd->args)
		return (FAILURE);
	index = 0;
	last_cmd->args[index] = ft_strdup(last_cmd->command);
	index++;
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->type == true)
			last_cmd->args[index] = append_vars(&temp);
		else
			last_cmd->args[index] = ft_strdup(temp->input);
		index++;
		temp = temp->next;
	}
	last_cmd->args[index] = NULL;
	*current_token = temp;
	return (SUCCESS);
}

int	append_args_echo(t_token **current_token, t_cmd *last_cmd)
{
	int		size;
	int		count;
	char	**new_tab;
	t_token	*temp;

	remove_empty(current_token);
	temp = *current_token;
	count = count_joined_arguments(temp);
	size = 0;
	while (last_cmd->args[size])
		size++;
	new_tab = malloc(sizeof(char *) * (count + size + 1));
	if (!new_tab)
		return (FAILURE);
	new_tab = copy_echo(last_cmd, temp, new_tab, size);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	while (temp->type == WORD || temp->type == VAR)
		temp = temp->next;
	*current_token = temp;
	return (SUCCESS);
}
