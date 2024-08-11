/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:40:14 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/28 03:54:25 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "minishell.h"

/* file input output */

bool	check_io(t_redir *io_fds);
bool	reset_io(t_redir *io_fds);
bool	redirect_io(t_redir *io_fds);

/* pipes */

void	close_pipes_fd(t_cmd *cmd_list, t_cmd *skip);
bool	setup_pipes(t_cmd *cmd_list, t_cmd *cmd);
bool	create_pipes(t_data *data);

#endif