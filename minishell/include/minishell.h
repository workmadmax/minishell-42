/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:46:46 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 02:18:08 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define VERSION "0.0.16"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>
# include "libft.h"
# include "struct.h"
# include "colors.h"
# include "defines.h"
# include "enum.h"
# include "env_vars.h"
# include "builtins.h"
# include "utils.h"
# include "parse.h"
# include "redir.h"
# include "tokenize.h"
# include "exec.h"
# include "signals.h"

#endif