# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 12:32:27 by yassine           #+#    #+#              #
#    Updated: 2023/11/01 10:24:02 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PROGRAM_NAME = Pointer
CC = clang++
INCLUDES = include
CPPFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -std=c++98
RM = rm -rf

SRCS = main.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(PROGRAM_NAME)
	@echo "Compilation terminée. Le programme $(PROGRAM_NAME) a été créé."

.cpp.o:
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "Compilation de $< terminée."

clean:
	@$(RM) $(OBJS)
	@echo "Nettoyage des fichiers objets terminé."

fclean: clean
	@$(RM) $(PROGRAM_NAME)
	@echo "Suppression du programme $(PROGRAM_NAME) terminée."

re: fclean all

.PHONY: all clean fclean re
