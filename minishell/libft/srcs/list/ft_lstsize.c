/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:27:13 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:30:09 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Counts the number of elements in a list.
 * 
 * @param lst The beginning of a list.
 * @return int Returns the length of a list.
 */
int	ft_lstsize(t_list *list)
{
	int			count;
	t_list		*temp;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
