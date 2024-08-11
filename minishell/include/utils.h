/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:18:13 by mdouglas          #+#    #+#             */
/*   Updated: 2023/04/01 23:40:01 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

/* error message */

char			*append_string(char *string, char *add);
void			error_msg(char *error_msg, char *detail, int quotes);
int				error_cmd_msg(char *command, char *detail, char *error_msg,
					int error_code);

/* libft */

int				ft_check_space(char c);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcat(char *dest, char *src);
void			*ft_realloc(void *ptr, size_t size);
char			*str_trim_start(char *str, size_t n);
char			**str_split_in_two(char *str, char sep);
char			*ft_strcpy(char *str1, char *str2);
size_t			ft_strnlen(const char *str, size_t max);
char			*ft_strndup(const char *str, size_t n);
char			*ft_strjoin_clear(char *s1, char *s2);
char			*ft_concat_sub(char *src, char *input, int start, int len);

long long int	ft_atol(const char *str);
long long int	ft_strtoll(const char *str, char **endptr, int base);

/* clean data */

void			ft_free_ptr(void *ptr);
void			ft_free_string(char **str);
void			free_io_fds(t_redir *io_fds);
void			free_data(t_data *data, bool clear);
void			free_heredoc(t_data *data, bool clear);

void			close_data(t_data *data, int exno);
void			close_fd(t_cmd *cmd_list, bool free_fd);

void			free_item(t_ht_items *item);
void			free_hashtable(t_hashtable *hashtable);

void			print_exit(void);

/* init data */

void			init_command_list(t_cmd **command_list);
void			init_io_fds(t_cmd *cmd_redir);
bool			init_data(t_data *data, char **env);

bool			init_env(t_data *data, char **envp);
t_hashtable		*init_hashtable(size_t size);
void			fill_env_table(t_hashtable *env_table, char **envp);

/* utils quotes */

int				remove_quotes(t_token **token);

/* heredoc utils */

bool			fill_heredoc(t_data *data, char *delim, int temp_fd);

/* utils */

int				cd_dir_check(char *path);
int				cd_oldpwd(t_data *data);
int				cd_pwd(t_data *data);
void			update_pwd_env(t_hashtable *env);
int				cd_parent_dir(t_data *data);
int				cd_dir_change(t_data *data, char *new_path);
int				cd_dir(t_data *data);

/* execute */

int				check_cmd(t_cmd *cmd);
int				check_access(t_cmd *cmd);
bool			check_cmd_is_dir(char *cmd);

#endif