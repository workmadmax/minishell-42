/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:19:26 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:51:55 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_args_default(t_token **current_token, t_cmd *last_cmd)
{
	int		index;
	int		count;
	t_token	*temp;

	index = 0;
	temp = *current_token;
	count = count_arguments(temp);
	last_cmd->args = malloc(sizeof(char *) * (count + 2));
	if (!last_cmd->args)
		return (FAILURE);
	temp = *current_token;
	index = 0;
	last_cmd->args[index] = ft_strdup(last_cmd->command);
	index++;
	while (temp->type == WORD || temp->type == VAR)
	{
		last_cmd->args[index] = ft_strdup(temp->input);
		index++;
		temp = temp->next;
	}
	last_cmd->args[index] = NULL;
	*current_token = temp;
	return (SUCCESS);
}

static char	**copy_default(t_cmd *last_cmd,
	t_token **current_token, char **new_tab, int size)
{
	int		index;
	t_token	*temp;

	index = 0;
	temp = *current_token;
	while (index < size)
	{
		new_tab[index] = last_cmd->args[index];
		index++;
	}
	while (temp->type == WORD || temp->type == VAR)
	{
		new_tab[index] = ft_strdup(temp->input);
		ft_free_string(&temp->input);
		index++;
		temp = temp->next;
	}
	new_tab[index] = NULL;
	return (new_tab);
}

int	append_args(t_token **current_token, t_cmd *last_cmd)
{
	int		index;
	int		size;
	char	**new_tab;
	t_token	*temp;

	index = 0;
	temp = *current_token;
	while (temp->type == WORD || temp->type == VAR)
	{
		index++;
		temp = temp->next;
	}
	size = 0;
	while (last_cmd->args[size])
		size++;
	new_tab = malloc(sizeof(char *) * (size + index + 1));
	if (!new_tab)
		return (FAILURE);
	new_tab = copy_default(last_cmd, current_token, new_tab, size);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	*current_token = temp;
	return (SUCCESS);
}

int	handle_args_default(t_token **current_token, t_cmd *last_cmd)
{
	if (!ft_strcmp(last_cmd->command, "echo"))
	{
		if (!(last_cmd->args))
			return (create_args_echo(current_token, last_cmd));
		else
			return (append_args_echo(current_token, last_cmd));
	}
	else
	{
		if (last_cmd && !(last_cmd->args))
			return (create_args_default(current_token, last_cmd));
		else
			return (append_args(current_token, last_cmd));
	}
	return (SUCCESS);
}
