/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:12:48 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:28:55 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Iterates the list 'lst' and applies
 * the function 'f' to the content of each element.
 * Creates a new list resulting of the
 * sucessive application of the function 'f'.
 * The 'del' function is used to
 * delete the content of an element if needed.
 * 
 * @param list The adress of a pointer to an element.
 * @param f The adress of the function used
 * to iterate on the list
 * @param del The adress of the function used
 * to delete the
 * content of an element if needed.
 * @return 't_list*' Returns the new list or
 * NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*listmap;
	t_list	*temp;
	void	*content;

	if (!list)
		return (NULL);
	listmap = NULL;
	while (list)
	{
		content = f(list->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&listmap, del);
			return (NULL);
		}
		ft_lstadd_back(&listmap, temp);
		list = list->next;
	}
	return (listmap);
}
