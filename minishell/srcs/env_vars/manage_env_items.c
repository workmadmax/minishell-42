/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env_items.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:18:49 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/27 18:25:04 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ht_items	*create_item(char *key, char *value)
{
	t_ht_items	*items;

	if (!key || !value)
		return (NULL);
	items = (t_ht_items *)malloc(sizeof(t_ht_items));
	if (!items)
		return (NULL);
	ft_memset(items, 0, sizeof(t_ht_items));
	items->key = ft_strdup(key);
	items->value = ft_strdup(value);
	items->next = NULL;
	if (!items->key || !items->value)
	{
		free_item(items);
		return (NULL);
	}
	return (items);
}

void	ht_add_update_items(t_hashtable *ht, char *key, char *value)
{
	t_ht_items	*item;
	size_t		i;

	item = create_item(key, value);
	if (!item)
	{
		error_cmd_msg("Error: malloc failed", NULL, NULL, 1);
		return ;
	}
	i = hash_function(key);
	if (!ht->items[i])
		ht->items[i] = item;
	else if (ft_strcmp(ht->items[i]->key, key) == 0)
	{
		free(ht->items[i]->value);
		ht->items[i]->value = ft_strdup(value);
		free_item(item);
	}
	else
		handle_linked_item(ht, item, i);
}

char	*get_env_item(t_hashtable *ht, char *key)
{
	int			hash;
	t_ht_items	*item;

	hash = hash_function(key);
	if (ht->items[hash] != NULL && ht->items[hash]->next == NULL)
		return (ht->items[hash]->value);
	else if (ht->items[hash] != NULL && ht->items[hash]->next != NULL)
	{
		item = ht->items[hash];
		while (item->next != NULL && ft_strcmp(item->key, key) != 0)
			item = item->next;
		if (ft_strcmp(item->key, key) == 0)
			return (item->value);
	}
	return ("\0");
}

static void	atrib_items_to_array(char ***env_table, t_hashtable *ht,
	size_t i, size_t *j)
{
	t_ht_items	*temp;

	if (ht->items[i] != NULL && ht->items[i]->next == NULL)
	{
		*env_table[*j] = ft_strjoin(ht->items[i]->key,
				ft_strjoin("=", ht->items[i]->value));
		j = j + 1;
	}
	else if (ht->items[i] != NULL && ht->items[i]->next != NULL)
	{
		temp = ht->items[i];
		while (temp->next != NULL)
		{
			*env_table[*j] = ft_strjoin(temp->key,
					ft_strjoin("=", temp->value));
			temp = temp->next;
		}
		*env_table[*j] = ft_strjoin(temp->key, ft_strjoin("=", temp->value));
		j = j + 1;
	}
}

char	**ht_to_array(t_hashtable *ht)
{
	size_t		i;
	size_t		j;
	char		**env_table;

	env_table = ft_calloc(ENVCAPACITY, sizeof(char *));
	if (!env_table)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ENVCAPACITY)
	{
		atrib_items_to_array(&env_table, ht, i, &j);
		i++;
	}
	return (env_table);
}
