/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:15 by mdouglas          #+#    #+#             */
/*   Updated: 2023/03/27 23:48:07 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/**
 * @brief A list of nodes with content.
 * it cotains a pointer to the element's
 * data and a pointer to the next node in
 * the list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* gnl */

char	*get_next_line(int fd);
// char	*get_reading(int fd, char *string);
// char	*get_string(char *string);
// char	*gnl_strjoin(char *string_one, char *string_two);
// char	*gnl_dup(char *string);

char	*get_next_line(int fd);
char	*ft_joinsub(char *saved, char *buff, int start, int len);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(char const *s1, char const *s2);
void	read_fd(char **line, char **save, int fd, int bf);
void	search_nl2(char *buff, int *iread, char **line, char **save);

/* printf */

int		ft_printf(const char *format, ...);
size_t	ft_parse(va_list args, char format);
size_t	handle_char(char character);
size_t	handle_hex(unsigned long x, int prefix, size_t cap);
size_t	handle_num(long long nbr);
size_t	handle_str(const char *string);

/* parse */

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *string);
char	*ft_itoa(int nbr);

/* list */

int		ft_lstsize(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *new_node);
void	ft_lstadd_front(t_list **list, t_list *new_node);
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstdelone(t_list *list, void (*del)(void *));
void	ft_lstiter(t_list *list, void (*f)(void *));
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

/* string */

char	**ft_split(char const *string, char c);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *string);
void	ft_striteri(char *string, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *string_one, char const *string_two);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *string);
char	*ft_strmapi(char const *string, char (*f)(unsigned int, char));
int		ft_strncmp(const char *string_one, const char *string_two, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *string, int c);
char	*ft_strtrim(char const *string_one, char const *set);
char	*ft_substr(char const *src, unsigned int start, size_t len);

/* memory */

void	ft_bzero(void *dest, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *ptr, int c, size_t len);
int		ft_memcmp(const void *string_one, const void *string_two, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *string_one, const void *string_two, size_t n);
void	*ft_memset(void *string, int c, size_t n);

/* put fd */

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *string, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putstr_fd(char *string, int fd);

/* checker */

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

#endif