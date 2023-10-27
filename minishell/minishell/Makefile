# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>               +#+ +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 23:33:05 by yasaidi           #+#    #+#              #
#    Updated: 2023/10/14 13:01:38 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program file name
NAME	= minishell

# Compiler and compilation flags
CC		= clang
CFLAGS	= -Werror -Wextra -Wall -g

# Build files and directories
SRC_PATH = ./src/
OBJ_PATH = ./objects/
INC_PATH = ./include/
SRC		=   main.c \
            bltins/cd_builtin.c \
            bltins/exit_builtin.c \
            bltins/unset_builtin.c \
            bltins/echo_builtin.c \
            bltins/export_builtin.c \
            bltins/env_builtin.c \
            bltins/pwd_builtin.c \
            env/alloc_env.c\
            env/get_env.c\
            exec/exec2.c \
            exec/exec.c \
            exec/executils.c \
            exec/get_cmd_path.c \
            exec/pipe.c \
            exec/redir.c \
            expand/expand_utils.c \
            expand/quote_stuff.c \
            expand/var_expand.c \
            expand/what_var.c \
            expand/get_val.c \
            expand/remove_quotes.c \
            expand/var_replace.c \
            lexer/input_parsing.c \
            lexer/lexical_grammar.c \
            lexer/tokenmaker.c \
            lexer/is_it_a_var.c \
            lexer/linked_list_tokens.c \
            lexer/tokenmaker_utils.c \
            parser/append_parser.c \
            parser/get_args_for_echo.c \
            parser/linked_list_cmd_cleaner.c \
            parser/word_parser.c \
            parser/command_parser.c \
            parser/heredoc_parser.c \
            parser/linked_list_command.c \
            parser/echo_args_utils.c \
            parser/heredoc_utils.c \
            parser/pipe_parser.c \
            parser/get_args.c \
            parser/input_parser.c \
            parser/trunc_parser.c \
            sigs/sigs.c \
            utils/error.c \
            utils/exit.c \
            utils/free.c \
            utils/random2.c \
            utils/random.c \
            utils/random3.c\
            utils/struct_init.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INC		= -I $(INC_PATH) -I $(LIBFT_PATH)

# Libft files and directories
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a

# Main rule
all: $(OBJ_PATH) $(LIBFT) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/bltins
	mkdir -p $(OBJ_PATH)/lexer
	mkdir -p $(OBJ_PATH)/expand
	mkdir -p $(OBJ_PATH)/parser
	mkdir -p $(OBJ_PATH)/env
	mkdir -p $(OBJ_PATH)/exec
	mkdir -p $(OBJ_PATH)/utils
	mkdir -p $(OBJ_PATH)/sigs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) -l readline

$(LIBFT):
	make -C $(LIBFT_PATH)

leak :
	valgrind --suppressions=ignore_readline    \
    --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes    \
    ./minishell

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean