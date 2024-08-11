# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 19:21:27 by mdouglas          #+#    #+#              #
#    Updated: 2023/03/27 23:41:13 by rotakesh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= libft.a

CC							= gcc
CFLAGS						= -Wall -Werror -Wextra
LIB							= ar rcs
RM							= rm -f
SAFE_MKDIR					= mkdir -p
INCLUDE						= libft.h

#								get_next_line.c get_read.c get_string.c \
#								gnl_dup.c gnl_strjoin.c
SRCS						= ft_isalnum.c ft_isalpha.c ft_isascii.c \
								ft_isdigit.c ft_isprint.c \
								ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
								ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
								ft_lstmap.c ft_lstnew.c ft_lstsize.c \
								ft_bzero.c ft_calloc.c ft_memchr.c \
								ft_memcmp.c ft_memcpy.c ft_memmove.c \
								ft_memset.c ft_atoi.c ft_itoa.c \
								ft_tolower.c ft_toupper.c \
								ft_parse.c ft_printf.c handle_char.c \
								handle_hex.c handle_number.c handle_string.c \
								ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
								ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
								ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
								ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
								ft_strrchr.c ft_strtrim.c ft_substr.c \
								gnl_utils.c get_next_line.c

VPATH						= srcs/checker/ srcs/gnl/ srcs/list/ \
								srcs/memory/ srcs/parse/ srcs/printf/ \
								srcs/put_fd/ srcs/string/
								
OBJS_DIR					= objects
OBJS						= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

$(OBJS_DIR)/%.o:			%.c
								$(CC) $(CFLAGS) -c $< -o $@ -I./include

all:						$(NAME)

$(NAME):					$(OBJS_DIR) $(OBJS)
								$(LIB) $(NAME) $(OBJS)
								
$(OBJS_DIR):
								mkdir -p $@

clean:
								$(RM) $(OBJS)
								
fclean:						clean
								$(RM) $(NAME)
								
re:							fclean all

.PHONY:						clean fclean all re

