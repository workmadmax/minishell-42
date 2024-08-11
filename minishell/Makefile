NAME					=	minishell
CC						=	gcc
CFLAGS					=	-Wall -Werror -Wextra -g3
CFLIB					=	-lreadline
RM						=	rm -rf
SAFE_MKDIR				=	mkdir -p
INCLUDE					=	-Iinclude -Ilibft/include

SRCS					=	main.c \
								clear_cmd_list.c \
								cmd_list.c \
								handle_append.c \
								handle_args_default.c \
								handle_args_echo.c \
								handle_heredoc.c \
								handle_input.c \
								handle_pipe.c \
								handle_quotes.c \
								handle_trunc.c \
								handle_word.c \
								handle_var.c \
								parse_utils.c \
								checkers.c clear_list.c \
								handle_user_input.c \
								token_list.c \
								token_utils.c \
								free_data.c \
								free_env_vars.c \
								close_data.c \
								error_cmd_msg.c \
								error_msg.c \
								ft_strcat.c \
								ft_strcmp.c \
								ft_mini_split.c \
								inits_data.c \
								init_env.c \
								remove.c \
								file_io.c pipes.c \
								exec_cmd.c \
								exec_path.c \
								exec_proc.c \
								exec_builtins.c \
								expand_var.c \
								hash_function.c \
								manage_env_items.c \
								manage_linked_env_items.c \
								manage_signals.c \
								cd.c \
								echo.c \
								env.c \
								export.c \
								pwd.c \
								unset.c \
								fill_heredoc.c \
								ft_strnlen.c \
								cd_utils.c \
								cd_check.c \
								exit.c \
								ft_strjoin_clear.c \
								ft_strtoll.c \
								cmd.c \
								inits_cmd_io.c

VPATH					=	./srcs/ ./srcs/parse/ ./srcs/tokenize \
								./srcs/utils/ ./srcs/utils/clean_data/ \
								./srcs/utils/error_msg/ ./srcs/utils/str/ \
								./srcs/utils/init_data/ ./srcs/utils/quotes/ \
								./srcs/exec/ ./srcs/redir/ ./srcs/env_vars\
								./srcs/utils/signals/ ./srcs/builtins \
								./srcs/utils/heredoc/ ./srcs/utils/cd/ \
								./srcs/utils/execute/

RED						= \e[91m
GREEN					= \e[92m
YELLOW					= \e[93m
RC						= \e[0m

LIBFT					=	$(LIBPATH)/libft.a
LIBPATH					=	./libft

OBJS_DIR				=	objects
OBJS					=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

$(OBJS_DIR)/%.o:		%.c
							$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

all:					$(NAME)

$(OBJS_DIR):
							@printf "$(YELLOW)Creating $(NAME) objects$(RC)\n"
							@$(SAFE_MKDIR) $@

$(OBJS_DIR)/%.o:		%.c
							@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
							@printf "."


$(NAME):				$(OBJS_DIR) $(OBJS)
							@printf "\n$(YELLOW)Creating LIBFT$(RC)\n"
							@$(MAKE) -s -C $(LIBPATH)
							@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CFLIB) -o $(NAME)
							@printf "\n$(GREEN)$(NAME) created$(RC)\n"

clean:
							@$(MAKE) -s -C $(LIBPATH) clean
							@$(RM) $(OBJS)
							@$(RM) $(OBJS_DIR)
							@printf "$(RED)$(NAME) objects removed$(RC)\n"

fclean:					clean
							@$(MAKE) -s -C $(LIBPATH) fclean
							@$(RM) $(OBJS) $(NAME)
							@printf "$(RED)$(NAME) removed$(RC)\n"

re:						fclean all

.PHONY:					all clean fclean re