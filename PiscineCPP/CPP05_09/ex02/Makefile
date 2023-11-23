# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 08:06:59 by yasaidi           #+#    #+#              #
#    Updated: 2023/11/23 08:53:18 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PROGRAM = Form

CC = g++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

SRCS = main.cpp \
	   AForm.cpp \
	   Bureaucrat.cpp \
	   ShrubberyCreationForm.cpp 
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