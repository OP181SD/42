# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 10:20:48 by yassine           #+#    #+#              #
#    Updated: 2023/10/27 10:21:33 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = Looser

CC = g++

INCLUDES = include

CPPFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -std=c++98

RM = rm -rf

SRCS =	main.cpp 
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