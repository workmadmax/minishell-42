/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:48 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 02:44:58 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*pwd;
	char	*old_pwd;

	old_pwd = malloc(sizeof(char) * 1024);
	pwd = getcwd(old_pwd, 1024);
	if (pwd == NULL)
		return (1);
	printf("%s\n", pwd);
	free(old_pwd);
	return (0);
}
