# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 13:25:04 by yasaidi           #+#    #+#              #
#    Updated: 2023/09/13 21:29:21 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= philo
INCS		:= philo.h
INCS_DIR	:= ./include
INCS		:=
SRC_DIR		:= src
BUILD_DIR	:= .build
SRCS		:= 	\
				main.c \
				initialisation.c \
				initalisation_mutex.c \
				display.c \
				routine.c\
				parsing.c \
				clear.c \
				action.c \
				time.c \
				dead.c \
				forks.c \
				cycle.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MMD -MP -I ${INCS_DIR} -g3 -pthread
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c $< -o $@
	# $(info CREATED $@)

run:
	./philo 2 400 200 200

leak:
	valgrind --tool=helgrind ./philo 2 100 200 200

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

-include $(DEPS)