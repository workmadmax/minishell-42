/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:04:38 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:24:29 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Iterates the list 'lst' and
 * applies the function 'f' to the
 * content of each element.
 * 
 * @param list The adress of a pointer
 * to an element
 * @param f The adress of the function
 * used to iterate on the list.
 */
void	ft_lstiter(t_list *list, void (*f)(void *))
{
	if (!list || !f)
		return ;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}
