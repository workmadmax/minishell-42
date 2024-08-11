/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:58:19 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:22:46 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Adds the 'new' element at the end of the list.
 * 
 * @param list The adress of a pointer to the first link of a list.
 * @param new_node The adress of a pointer to the element to be
 * add to the list.
 */
void	ft_lstadd_back(t_list **list, t_list *new_node)
{
	t_list	*temp;

	if (new_node == NULL)
		return ;
	if (*list == NULL)
		*list = new_node;
	else
	{
		temp = ft_lstlast(*list);
		temp->next = new_node;
	}
}
