/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:20:45 by rotakesh          #+#    #+#             */
/*   Updated: 2023/04/02 01:32:27 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARS_H
# define ENV_VARS_H

# include "minishell.h"

char		*expand_var(t_data *data, t_token *token);
size_t		hash_function(char *key);
t_ht_items	*create_item(char *key, char *value);
void		ht_add_update_items(t_hashtable *ht, char *key, char *value);
char		*get_env_item(t_hashtable *ht, char *key);
int			add_update_linked_item(t_hashtable *ht, t_ht_items *item, size_t i);
void		handle_linked_item(t_hashtable *ht, t_ht_items *item, size_t i);
void		remove_linked_item(t_hashtable *ht, size_t index, char *temp);
char		**ht_to_array(t_hashtable *ht);
bool		handle_var(t_data *data);

#endif