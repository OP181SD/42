# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:07:18 by yasaidi           #+#    #+#              #
#    Updated: 2023/03/04 16:40:17 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
SRC_DIR		:= src
BUILD_DIR	:= .build
SRCS		:= 	\
			push_swap.c \
			do_op/do_sa.c \
			do_op/do_sb.c \
			do_op/is_sorted.c \
			utils/error.c \
			utils/parsing.c\
			utils/min_max.c\
			radix/utils.c \
			radix/radix.c \
			lst/ft_lstnew.c\
			lst/ft_lstsize.c\
			lst/ft_lstadd_back.c\
			lst/ft_lstadd_front.c\
			lst/ft_lstlast.c\
			lst/ft_lstdelone.c\
			lst/ft_lstclear.c \
			lst/ft_lstpre_last.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc -g3
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft
INCLUDES	:= -Ilibft/include -I./include

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT: