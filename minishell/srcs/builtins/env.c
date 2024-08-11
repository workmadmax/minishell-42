/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:48 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 01:57:53 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envvars(t_hashtable *env_table)
{
	t_ht_items	*temp_item;
	int			i;

	i = 0;
	while (i < ENVCAPACITY)
	{
		if (env_table->items[i] != NULL && env_table->items[i]->next == NULL)
			printf("%s=%s\n", env_table->items[i]->key,
				env_table->items[i]->value);
		else if (env_table->items[i] != NULL
			&& env_table->items[i]->next != NULL)
		{
			temp_item = env_table->items[i];
			while (temp_item->next != NULL)
			{
				printf("%s=%s\n", temp_item->key, temp_item->value);
				temp_item = temp_item->next;
			}
			printf("%s=%s\n", temp_item->key, temp_item->value);
		}
		i++;
	}
}

int	env(t_hashtable *ht, char **args)
{
	if (args[1] || !ht)
	{
		error_cmd_msg("env", NULL, "Options or parametes are forbidden", 1);
		return (EXIT_FAILURE);
	}
	print_envvars(ht);
	return (EXIT_SUCCESS);
}
