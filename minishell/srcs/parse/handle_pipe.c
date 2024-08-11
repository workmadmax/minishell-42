/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:29:08 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:54:09 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipe(t_cmd **cmd, t_token **token_list)
{
	t_cmd	*last_cmd;

	last_cmd = add_last_cmd(*cmd);
	last_cmd->pipe_out = true;
	add_back_cmd(&last_cmd, add_new_cmd(false));
	*token_list = (*token_list)->next;
}
