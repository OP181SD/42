# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 15:54:33 by yasaidi           #+#    #+#              #
#    Updated: 2023/10/22 15:55:28 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = PhoneBook

CC = g++

INCLUDES = include

CPPFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -std=c++98

RM = rm -rf

SRCS =	PhoneBook.cpp \
		Contact.cpp 

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