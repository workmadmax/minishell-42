/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:24:13 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:57:41 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_cmd_list(t_cmd **command_list, void (*del)(void *))
{
	t_cmd	*temp;

	temp = NULL;
	while (*command_list != NULL)
	{
		temp = (*command_list)->next;
		list_delone_cmd(*command_list, del);
		*command_list = temp;
	}
}

void	list_delone_cmd(t_cmd *command_list, void (*del)(void *))
{
	if (command_list->command)
		(*del)(command_list->command);
	if (command_list->args)
		ft_free_string(command_list->args);
	if (command_list->pipe_fd)
		(*del)(command_list->pipe_fd);
	if (command_list->redir)
		free_io_fds(command_list->redir);
	(*del)(command_list);
}
