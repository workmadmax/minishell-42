/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:58:51 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 02:09:16 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(int sig)
{
	(void) sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(0, "\n", 1);
	rl_redisplay();
}

void	ft_sighere(int sig)
{
	(void)sig;
	exit(1);
}
