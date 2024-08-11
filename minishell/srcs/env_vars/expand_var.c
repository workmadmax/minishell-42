/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:21:52 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 01:21:11 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_tilde(t_data *data, char *input)
{
	free(input);
	return (ft_strdup(get_env_item(data->env, "HOME")));
}

static char	*expand_exit_code(t_data *data, char *input)
{
	char	*exit_code;
	char	*input_trimmed;
	char	*res;

	exit_code = ft_itoa(data->exit_code);
	input_trimmed = str_trim_start(input, 2);
	res = ft_strjoin(exit_code, input_trimmed);
	free(input_trimmed);
	free(exit_code);
	free(input);
	return (res);
	(void)data;
}

static char	*expand_var_default(t_data *data, char *input)
{
	char	*input_trimmed;
	char	*res;

	if (ft_strncmp(input, "$?", 2) == 0)
		return (expand_exit_code(data, input));
	else if (ft_strlen(input) == 1 && input[0] == '$')
		return (input);
	input_trimmed = str_trim_start(input, 1);
	res = ft_strdup(get_env_item(data->env, input_trimmed));
	free(input);
	free(input_trimmed);
	return (res);
}

static char	*expand_var_double_quotes(t_data *data, char *input)
{
	char	*res;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(1, 1);
	while (input[i])
	{
		if (input[i] == '$')
		{
			res = ft_concat_sub(res, input, j, i - j);
			j = i++;
			while (ft_isalnum(input[i]) || input[i] == '?')
				i++;
			temp = expand_var_default(data, ft_substr(input, j, i - j));
			res = ft_strjoin_clear(res, temp);
			j = i;
		}
		i++;
	}
	res = ft_concat_sub(res, input, j, i - j);
	free(input);
	return (res);
}

char	*expand_var(t_data *data, t_token *token)
{
	if (token->input[0] == 126 && ft_strlen(token->input) == 1)
		return (expand_tilde(data, token->input));
	else if (check_quotes(token->input) == DEFAULT)
		return (expand_var_default(data, token->input));
	return (expand_var_double_quotes(data, token->input));
}
