/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:48 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/31 08:46:41 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(t_hashtable *ht, char *input)
{
	size_t		index;

	if (input == NULL)
		return (0);
	index = hash_function(input);
	if (ht->items[index] == NULL)
		return (0);
	if (ht->items[index] != NULL && ht->items[index]->next == NULL)
	{
		free_item(ht->items[index]);
		ht->items[index] = NULL;
	}
	else if (ft_strncmp(ht->items[index]->key, input, ft_strlen(input)) == 0)
		ht->items[index] = ht->items[index]->next;
	else if (ht->items[index] != NULL)
		remove_linked_item(ht, index, input);
	return (0);
}
