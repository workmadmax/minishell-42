/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:18:17 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:57:27 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*add_last_cmd(t_cmd *command_list)
{
	while (command_list->next != NULL)
		command_list = command_list->next;
	return (command_list);
}

t_cmd	*add_new_cmd(bool value)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!(new_cmd))
		return (NULL);
	ft_memset(new_cmd, 0, sizeof(t_cmd));
	new_cmd->pipe_out = value;
	init_command_list(&new_cmd);
	return (new_cmd);
}

void	add_back_cmd(t_cmd **command_list, t_cmd *new_cmd)
{
	t_cmd	*start;

	start = *command_list;
	if (start == NULL)
	{
		*command_list = new_cmd;
		return ;
	}
	if (command_list && *command_list && new_cmd)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_cmd;
		new_cmd->prev = start;
	}
}

static void	setup_args_cmd(t_data *data)
{
	t_cmd	*cmd;

	if (!data || !data->cmd)
		return ;
	cmd = data->cmd;
	while (cmd && cmd->command)
	{
		if (!cmd->args)
		{
			cmd->args = malloc(sizeof * cmd->args * 2);
			cmd->args[0] = ft_strdup(cmd->command);
			cmd->args[1] = NULL;
		}
		cmd = cmd->next;
	}
	cmd = add_last_cmd(data->cmd);
}

void	create_cmd_list(t_data *data, t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	if (temp->type == END)
		return ;
	while (temp->next != NULL)
	{
		if (temp == token_list)
			add_back_cmd(&data->cmd, add_new_cmd(false));
		if (temp->type == WORD || temp->type == VAR)
			handle_word(&data->cmd, &temp);
		else if (temp->type == INPUT)
			handle_input(&data->cmd, &temp);
		else if (temp->type == TRUNC)
			handle_trunc(&data->cmd, &temp);
		else if (temp->type == HEREDOC)
			handle_heredoc(data, &data->cmd, &temp);
		else if (temp->type == APPEND)
			handle_append(&data->cmd, &temp);
		else if (temp->type == PIPE)
			handle_pipe(&data->cmd, &temp);
		else if (temp->type == END)
			break ;
	}
	setup_args_cmd(data);
}
