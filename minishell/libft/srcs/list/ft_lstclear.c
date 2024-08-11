/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:52:06 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:23:43 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Deletes and frees thegiven element
 * and every successor of that element,
 * using the function 'del' and free(3).
 * Finally, the pointer to the list must
 * be set to NULL.
 * 
 * @param lst The adress of a pointer to an element
 * @param del The adress of the function used
 * to delete the content of the element.
 */
void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*temp;

	if (!*list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		ft_lstdelone(*list, del);
		*list = temp;
	}
	*list = 0;
}
