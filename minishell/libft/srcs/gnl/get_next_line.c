/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:54:46 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/27 23:42:40 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Reads a line from a file descriptor
 * 
 * @param fd file descriptor to read.
 * @return Return a string including \\n if is a line.
 * In case of the file dont have \\n return
 * a string without \\n, NULL if the file is
 * empty or error occurred.
 */
// char	*get_next_line(int fd)
// {
// 	char		*string;
// 	static char	*buffer;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
// 		return (NULL);
// 	buffer = get_reading(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	string = get_string(buffer);
// 	buffer = gnl_dup(buffer);
// 	return (string);
// }
char	*get_next_line(int fd)
{
	static char	*save[511];
	char		*line;
	int			i;
	char		*temp;

	line = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 511)
		return (NULL);
	if (save[fd])
	{
		temp = ft_strjoin(save[fd], "");
		free(save[fd]);
		save[fd] = NULL;
		search_nl2(temp, &i, &line, &save[fd]);
		free(temp);
		if (i == 0)
			return (line);
	}
	read_fd(&line, &save[fd], fd, BUFFER_SIZE);
	return (line);
}
