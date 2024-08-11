/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:18:48 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:29:27 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Allocates (with malloc(3))
 * and returns a new element.
 * The variable 'content' is initialized
 * with the value of the
 * parameter 'content'. The variable 'next'
 * is initialized to NULL.
 * 
 * @param content The content to create
 * the new element with.
 * @return t_list* The new element
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
