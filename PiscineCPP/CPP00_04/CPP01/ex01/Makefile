# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 11:37:38 by yassine           #+#    #+#              #
#    Updated: 2023/11/01 13:20:59 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = Zombie

CC = g++

INCLUDES = include

CPPFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -std=c++98

RM = rm -rf

SRCS =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(PROGRAM)
	@echo "Compilation terminée. L'exécutable $(PROGRAM) a été créé."

.cpp.o:
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $<."

clean:
	@$(RM) $(OBJS)
	@echo "Suppression des fichiers objets terminée."

fclean: clean
	@$(RM) $(PROGRAM)
	@echo "Suppression de l'exécutable $(PROGRAM) terminée."

re: fclean all

.PHONY: all clean fclean re