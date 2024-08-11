/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:09:06 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:24:56 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Returns the last element of the list.
 * 
 * @param lst The beginning of the listç.
 * @return 't_list*' Returns the last element
 * of the list. Return NULL if 'list' is empety
 * or is already in the last element.
 */
t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}
