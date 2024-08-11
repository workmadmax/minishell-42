/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:48 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 00:45:28 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_str_isalnum(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i++]) != 1)
			return (0);
	}
	return (1);
}

void	print_exportvars(t_hashtable *env_table)
{
	t_ht_items	*temp_item;
	int			i;

	i = 0;
	while (i < ENVCAPACITY)
	{
		if (env_table->items[i] != NULL && env_table->items[i]->next == NULL)
			printf("declare -x %s=\"%s\"\n", env_table->items[i]->key,
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

static void	free_key_value_array(char **key_value)
{
	ft_free_ptr(key_value[0]);
	ft_free_ptr(key_value[1]);
	free(key_value);
}

int	ft_export(t_hashtable *ht, char *input)
{
	char	**key_value;

	if (!input)
	{
		print_exportvars(ht);
		return (0);
	}
	if (ft_strchr(input, '=') == NULL)
	{
		if (!ft_str_isalnum(input) || ft_isdigit(input[0]))
			return (error_cmd_msg("export", input, "not a valid identifier",
					1));
		ht_add_update_items(ht, input, "");
		return (0);
	}
	key_value = str_split_in_two(input, '=');
	if (!ft_str_isalnum(key_value[0]) || ft_strlen(key_value[0]) == 0
		|| ft_strlen(key_value[1]) == 0)
	{
		free_key_value_array(key_value);
		return (error_cmd_msg("export", input, "not a valid identifier", 1));
	}
	ht_add_update_items(ht, key_value[0], key_value[1]);
	free_key_value_array(key_value);
	return (0);
}
