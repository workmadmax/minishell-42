/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_linked_env_items.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:38:32 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 02:01:07 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_update_linked_item(t_hashtable *ht, t_ht_items *item, size_t i)
{
	t_ht_items	*item_list;

	item_list = ht->items[i];
	while (item_list->next != NULL)
	{
		if (ft_strcmp(item_list->next->key, item->key) == 0)
		{
			ft_strcpy(item_list->next->value, item->value);
			return (1);
		}
		item_list = item_list->next;
	}
	item_list->next = item;
	return (0);
}

void	handle_linked_item(t_hashtable *ht, t_ht_items *item, size_t i)
{
	if (ht->items[i]->next == NULL)
		ht->items[i]->next = item;
	else
		add_update_linked_item(ht, item, i);
}

void	remove_linked_item(t_hashtable *ht, size_t index, char *temp)
{
	t_ht_items	*item;
	t_ht_items	*item_temp;

	item = ht->items[index];
	item_temp = NULL;
	while (item->next != NULL)
	{
		if (ft_strcmp(item->next->key, temp) == 0)
		{
			if (item->next->next != NULL)
				item_temp = item->next->next;
			item->next = item_temp;
			break ;
		}
		item = item->next;
	}
}
