/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:07:22 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 02:17:31 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_prompt(char *user, char *pwd)
{
	char	*prompt;
	size_t	prompt_len;

	if (!user || !pwd)
		return (NULL);
	prompt_len = ft_strlen(user) + ft_strlen(pwd) + 46;
	prompt = ft_calloc(prompt_len, sizeof(char));
	if (!prompt)
		return (NULL);
	ft_strlcat(prompt, GREEN, prompt_len);
	ft_strlcat(prompt, user, prompt_len);
	ft_strlcat(prompt, RESET_COLORS ":", prompt_len);
	ft_strlcat(prompt, BLUE, prompt_len);
	ft_strlcat(prompt, pwd, prompt_len);
	ft_strlcat(prompt, YELLOW, prompt_len);
	ft_strlcat(prompt, " ", prompt_len);
	ft_strlcat(prompt, VERSION, prompt_len);
	ft_strlcat(prompt, " ", prompt_len);
	ft_strlcat(prompt, RESET_COLORS, prompt_len);
	ft_strlcat(prompt, "$ ", prompt_len);
	return (prompt);
}

void	minishell(t_data *data)
{
	char	*prompt;

	while (1)
	{
		prompt = create_prompt(get_env_item(data->env, "USER"),
				get_env_item(data->env, "PWD"));
		data->user_input = readline(prompt);
		ft_free_ptr(prompt);
		if (!data->user_input || ft_strcmp(data->user_input, "exit") == 0)
			break ;
		if (handle_user_input(data) == true)
			data->exit_code = exec_proc(data);
		free_data(data, false);
	}
}

static bool	check_init(t_data *data, char **argv, char **envp)
{
	if (!envp || argv == NULL)
		return (false);
	ft_memset(data, 0, sizeof(t_data));
	if (!init_data(data, envp))
	{
		error_msg("minishell", "failed to initialize", false);
		free_data(data, true);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc != 1 || argv[1] != NULL)
		return (false);
	data = malloc(sizeof(t_data));
	if (!data)
		return (false);
	if (!check_init(data, argv, envp))
	{
		error_cmd_msg("minishell", "failed to initialize", NULL, false);
		close_data(data, EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
	minishell(data);
	close_data(data, data->exit_code);
	return (EXIT_SUCCESS);
}
