/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:07:10 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:23:11 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Adds the element 'new' at the
 * beginning of the list.
 * 
 * @param list The adress of a pointer to the first
 * link of a list.
 * @param new_node The adress of a pointerto
 * the element to be added to the list.
 */
void	ft_lstadd_front(t_list **list, t_list *new_node)
{
	t_list	*element;

	if (*list == NULL)
		*list = new_node;
	else
	{
		element = new_node;
		element->next = *list;
		*list = element;
	}
}
