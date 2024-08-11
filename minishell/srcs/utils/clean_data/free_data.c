/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:03 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/27 23:07:50 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_string(char **str)
{
	int	index;

	index = 0;
	if (str)
	{
		while (str[index])
		{
			if (str[index])
			{
				ft_free_ptr(str[index]);
				str[index] = NULL;
			}
			index++;
		}
		free(str);
		str = NULL;
	}
}

void	free_io_fds(t_redir *io_fds)
{
	if (!io_fds)
		return ;
	reset_io(io_fds);
	if (io_fds->heredoc_delim && io_fds->inside_heredoc)
		ft_free_ptr(io_fds->heredoc_delim);
	else if (io_fds->heredoc_delim)
	{
		unlink(io_fds->file_in);
		ft_free_ptr(io_fds->heredoc_delim);
	}
	if (io_fds->file_in)
		ft_free_ptr(io_fds->file_in);
	if (io_fds->file_out)
		ft_free_ptr(io_fds->file_out);
	if (io_fds)
		ft_free_ptr(io_fds);
}

void	free_data(t_data *data, bool clear)
{
	if (data && data->user_input)
	{
		ft_free_ptr(data->user_input);
		data->user_input = NULL;
	}
	if (data->prompt)
		ft_free_ptr(data->prompt);
	if (data && data->token)
		clear_list_token(&data->token, &ft_free_ptr);
	if (data && data->cmd)
		clear_cmd_list(&data->cmd, &ft_free_ptr);
	if (clear == true)
	{
		if (data && data->work_dir)
			ft_free_ptr(data->work_dir);
		if (data && data->old_dir)
			ft_free_ptr(data->old_dir);
		if (data->env)
			free_hashtable(data->env);
		if (data)
			ft_free_ptr(data);
		clear_history();
	}
}

void	free_heredoc(t_data *data, bool clear)
{
	if (data && data->user_input)
	{
		ft_free_ptr(data->user_input);
		data->user_input = NULL;
	}
	if (data->prompt)
		ft_free_ptr(data->prompt);
	if (data && data->token)
		clear_list_token(&data->token, &ft_free_ptr);
	if (data && data->cmd)
		clear_cmd_list(&data->cmd, &ft_free_ptr);
	if (clear == true)
	{
		if (data && data->work_dir)
			ft_free_ptr(data->work_dir);
		if (data && data->old_dir)
			ft_free_ptr(data->old_dir);
		if (data->env)
			free_hashtable(data->env);
		if (data)
			free(data);
		rl_clear_history();
	}
}
