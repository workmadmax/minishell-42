/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:46:57 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/28 03:47:31 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	open_heredoc(t_data *data, t_redir *io_fds)
{
	int		temp_fd;
	bool	status;
	char	*delim;

	status = true;
	temp_fd = open(io_fds->file_in, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	io_fds->inside_heredoc = true;
	delim = ft_strdup(io_fds->heredoc_delim);
	status = fill_heredoc(data, delim, temp_fd);
	free(delim);
	close(temp_fd);
	io_fds->inside_heredoc = false;
	return (status);
}

static char	*get_name_heredoc(void)
{
	int		index;
	char	*name;
	char	*nbr;

	index = 0;
	nbr = ft_itoa(index);
	if (!nbr)
		return (NULL);
	name = ft_strjoin("/tmp/minishell_heredoc", nbr);
	while (open(name, O_RDONLY) != -1)
	{
		free(name);
		free(nbr);
		index++;
		nbr = ft_itoa(index);
		if (!nbr)
			return (NULL);
		name = ft_strjoin("/tmp/minishell_heredoc", nbr);
	}
	free(nbr);
	return (name);
}

static char	*get_delim(char *delim, bool *quotes)
{
	int	size;

	size = ft_strlen(delim);
	if (size >= 2 && delim[0] == '\'' && delim[size - 1] == '\'')
	{
		*quotes = true;
		return (ft_strndup(delim + 1, size - 2));
	}
	else if (size >= 2 && delim[0] == '\"' && delim[size - 1] == '\"')
	{
		*quotes = true;
		return (ft_strndup(delim + 1, size - 2));
	}
	else
		return (ft_strdup(delim));
	return (ft_strdup(delim));
}

void	handle_heredoc(t_data *data, t_cmd **cmd, t_token **token)
{
	t_token	*temp;
	t_cmd	*new_cmd;
	t_redir	*io_fds;

	temp = *token;
	new_cmd = add_last_cmd(*cmd);
	init_io_fds(new_cmd);
	io_fds = new_cmd->redir;
	if (!remove_old_reference(io_fds, true))
		return ;
	io_fds->file_in = get_name_heredoc();
	io_fds->heredoc_delim = get_delim(temp->next->input,
			&(io_fds->heredoc_quotes));
	if (open_heredoc(data, io_fds))
		io_fds->fd_in = open(io_fds->file_in, O_RDONLY);
	else
		io_fds->fd_in = -1;
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token = temp;
}
