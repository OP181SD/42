# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:34:50 by yasaidi           #+#    #+#              #
#    Updated: 2024/02/03 11:35:02 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PROGRAM_NAME = PmergeMe

CC = c++
CPPFLAGS = -Wall -Werror -Wextra  -std=c++98
RM = rm -rf

SRCS = main.cpp \
       PmergeMe.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(PROGRAM_NAME)
	@echo "Compilation terminée. L'exécutable $(PROGRAM_NAME) a été créé."

.cpp.o:
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $<."

clean:
	@$(RM) $(OBJS)
	@echo "Suppression des fichiers objets terminée."

fclean: clean
	@$(RM) $(PROGRAM_NAME)
	@echo "Suppression de l'exécutable $(PROGRAM_NAME) terminée."

re: fclean all

.PHONY: all clean fclean re