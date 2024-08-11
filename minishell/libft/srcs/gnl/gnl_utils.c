/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:38:58 by rotakesh          #+#    #+#             */
/*   Updated: 2023/03/27 23:48:01 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinsub(char *saved, char *buff, int start, int len)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (ft_strlen(saved) + start + len + 1));
	i = 0;
	while (saved[i] != '\0')
	{
		result[i] = saved[i];
		i++;
	}
	while (buff[start] != '\0' && len-- > 0)
	{
		result[i++] = buff[start];
		start++;
	}
	result[i] = '\0';
	free(saved);
	return (result);
}

void	search_nl2(char *buff, int *iread, char **line, char **save)
{
	size_t	i;

	i = 0;
	if (!*line)
		*line = ft_strjoin("", "");
	while (i < ft_strlen(buff))
	{
		if (buff[i] != '\n')
			i++;
		else if (buff[i] == '\n')
		{
			*iread = 0;
			if (!*save)
				*save = ft_strjoin("", "");
			*save = ft_joinsub(*save, buff, i + 1, ft_strlen(buff) - i);
			break ;
		}
	}
	*line = ft_joinsub(*line, buff, 0, i + 1);
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

void	read_fd(char **line, char **save, int fd, int bf)
{
	char	*buff;
	int		iread;

	iread = bf;
	while (iread == bf)
	{
		buff = malloc(sizeof(char) * (bf + 1));
		iread = read(fd, buff, bf);
		if (iread > 0)
		{
			buff[iread] = 0;
			search_nl2(buff, &iread, &*line, &*save);
		}
		else if (iread < 0)
			*line = NULL;
		free(buff);
	}
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*result;
// 	int		iresult;
// 	int		i;

// 	i = 0;
// 	iresult = 0;
// 	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	while (s1[i] != '\0')
// 	{
// 		result[iresult] = s1[i];
// 		iresult++;
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i] != '\0')
// 	{
// 		result[iresult] = s2[i];
// 		iresult++;
// 		i++;
// 	}
// 	result[iresult] = '\0';
// 	return (result);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	count;

// 	count = 0;
// 	while (str[count] != '\0')
// 		count++;
// 	return (count);
// }
