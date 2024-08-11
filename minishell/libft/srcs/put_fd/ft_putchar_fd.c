/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:54:24 by mdouglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:45:12 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Outputs the character 'c' to
 * the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on
 * which to write.
 * @return None.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
