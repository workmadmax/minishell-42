/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:58:02 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:24:07 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Takes as a parameter an element and
 * frees the memory of the element's content
 * using the function 'del' given as
 * a parameter and free the element.
 * The memory of 'next' must not be freed.
 * 
 * @param lst The element to free.
 * @param del The adress of the function used
 * to delete the content.
 */
void	ft_lstdelone(t_list *list, void (*del)(void *))
{
	if (!list)
		return ;
	del(list->content);
	free(list);
}
