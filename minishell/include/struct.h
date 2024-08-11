/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:50:38 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/02 01:17:13 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct s_token
{
	int				type;
	int				status;
	char			*input;
	char			*backup;
	bool			join;
	bool			var_status;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_redir
{
	int				fd_in;
	int				fd_out;
	int				stdin_bkp;
	int				stdout_bkp;
	char			*file_in;
	char			*file_out;
	char			*heredoc_delim;
	bool			heredoc_quotes;
	bool			inside_heredoc;
	bool			fd_in_error;
}	t_redir;

typedef struct s_command
{
	int					*pipe_fd;
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_out;
	struct s_redir		*redir;
	struct s_command	*next;
	struct s_command	*prev;
}	t_cmd;

typedef struct s_ht_items {
	char				*key;
	char				*value;
	struct s_ht_items	*next;
}	t_ht_items;

typedef struct s_hashtable {
	t_ht_items	**items;
	size_t		count;
	size_t		size;
}	t_hashtable;

typedef struct s_data
{
	t_hashtable		*env;
	char			*user_input;
	char			*input;
	char			*prompt;
	char			*work_dir;
	char			*old_dir;
	bool			is_interactive;
	pid_t			pid;
	t_cmd			*cmd;
	t_token			*token;
	int				exit_code;
}	t_data;

#endif