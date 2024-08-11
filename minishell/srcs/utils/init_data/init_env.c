/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:03:11 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 00:06:43 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_env(t_data *data, char **envp)
{
	data->env = init_hashtable(ENVCAPACITY);
	if (data->env == NULL)
	{
		error_cmd_msg("Error: malloc failed", NULL, NULL, 1);
		return (false);
	}
	fill_env_table(data->env, envp);
	return (true);
}

t_hashtable	*init_hashtable(size_t size)
{
	t_hashtable	*hashtable;
	size_t		i;

	i = 0;
	hashtable = malloc(sizeof(t_hashtable));
	if (!hashtable)
		return (NULL);
	hashtable->size = size;
	hashtable->items = ft_calloc(hashtable->size, sizeof(t_ht_items));
	if (!hashtable->items)
		return (NULL);
	while (i < hashtable->size)
		hashtable->items[i++] = NULL;
	return (hashtable);
}

void	fill_env_table(t_hashtable *env_table, char **envp)
{
	int		index;
	char	**split_env;

	index = 0;
	while (envp[index] != NULL)
	{
		split_env = str_split_in_two(envp[index], '=');
		if (split_env)
		{
			ht_add_update_items(env_table, split_env[0], split_env[1]);
			ft_free_ptr(split_env[0]);
			ft_free_ptr(split_env[1]);
			free(split_env);
		}
		index++;
	}
}
