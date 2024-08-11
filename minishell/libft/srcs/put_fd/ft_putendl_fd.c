/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:56:28 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:45:30 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Outputs the string 's' to the given
 * file descriptor followed by a newline.
 * 
 * @param string The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
*/
void	ft_putendl_fd(char *string, int fd)
{
	ft_putstr_fd(string, fd);
	write(fd, "\n", 1);
}
