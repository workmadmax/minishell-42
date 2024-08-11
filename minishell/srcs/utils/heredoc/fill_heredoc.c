/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:45:28 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 02:06:49 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_rl_exit(char *input)
{
	free(input);
	exit(EXIT_SUCCESS);
}

void	start_input_heredoc(t_data *data, char *delim)
{
	free_data(data, true);
	free(delim);
	signal(SIGINT, ft_sighere);
}

static bool	input_heredoc(t_data *data, char *delim, int temp_fd)
{
	pid_t	pid;
	int		child_status;
	char	*input;

	pid = fork();
	if (pid < 0)
		return (error_cmd_msg("heredoc", "fork failed", NULL, false));
	else if (pid == 0)
	{
		start_input_heredoc(data, delim);
		input = readline("> ");
		if (!input)
			free_rl_exit(input);
		if (input[0] == 0)
			write(temp_fd, "\n", 1);
		else
			write(temp_fd, input, ft_strlen(input));
		free_rl_exit(input);
	}
	wait(&child_status);
	if (WIFEXITED(child_status) && WEXITSTATUS(child_status) == EXIT_SUCCESS)
		return (true);
	return (false);
}

static bool	check_input(char *temp, char *delim, int fd)
{
	char	*eof_msg;

	eof_msg = ft_strjoin("warning: here-document at line 1 delimited by ",
			"end-of-file (wanted `EOF')");
	if (temp == NULL)
	{
		error_cmd_msg("bash", eof_msg, NULL, true);
		close(fd);
		free(temp);
		free(eof_msg);
		return (true);
	}
	else if (ft_strcmp(temp, delim) == 0)
	{
		close(fd);
		free(temp);
		free(eof_msg);
		return (true);
	}
	free(eof_msg);
	return (false);
}

bool	fill_heredoc(t_data *data, char *delim, int temp_fd)
{
	int		status;
	int		fd;
	char	*line;

	while (1)
	{
		fd = open("/tmp/minitmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		status = input_heredoc(data, delim, fd);
		close(fd);
		if (!status)
			break ;
		fd = open("/tmp/minitmp", O_RDONLY);
		line = get_next_line(fd);
		if (check_input(line, delim, fd))
			break ;
		if (line[0] == '\n')
			ft_putstr_fd(line, temp_fd);
		else
			ft_putendl_fd(line, temp_fd);
		close(fd);
		free(line);
	}
	unlink("/tmp/minitmp");
	return (status);
}
