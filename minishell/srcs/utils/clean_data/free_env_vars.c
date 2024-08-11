/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:35:04 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 02:05:48 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_item(t_ht_items *item)
{
	if (item != NULL)
	{
		if (item->key)
			ft_free_ptr(item->key);
		if (item->value)
			ft_free_ptr(item->value);
		if (item->next)
			free_item(item->next);
		ft_free_ptr(item);
	}
}

void	free_hashtable(t_hashtable *hashtable)
{
	size_t	i;

	i = 0;
	while (i < hashtable->size)
	{
		if (hashtable->items[i] != NULL)
			free_item(hashtable->items[i]);
		i++;
	}
	free(hashtable->items);
	free(hashtable);
}
