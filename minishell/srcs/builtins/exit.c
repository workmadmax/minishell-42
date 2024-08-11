/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:05:54 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 01:58:08 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_data *data, char **args)
{
	int		exit_code;
	char	*endptr;

	exit_code = 0;
	if (args[1] != NULL)
	{
		exit_code = ft_strtoll(args[1], &endptr, 10);
		if (*endptr != '\0' || endptr == args[1])
			return (error_cmd_msg(args[0], NULL,
					"numeric argument required", 2));
	}
	if (args[2] != NULL)
		return (error_cmd_msg(args[0], NULL, "too many arguments", 1));
	close_data(data, exit_code);
	return (0);
}
