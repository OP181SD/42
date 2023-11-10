# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 11:03:03 by yassine           #+#    #+#              #
#    Updated: 2023/11/10 10:05:26 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLAPTRAP = FragTrap

CC = clang++

INCLUDES = include

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

SRCS = ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
	   	main.cpp 

OBJS = $(SRCS:%.cpp=%.o)

all: $(CLAPTRAP)

$(CLAPTRAP): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(CLAPTRAP)
	@echo "Compilation terminée. L'exécutable $(CLAPTRAP) a été créé."

.cpp.o:
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $<."

clean:
	@$(RM) $(OBJS)
	@echo "Suppression des fichiers objets terminée." 

fclean: clean
	@$(RM) $(CLAPTRAP)
	@echo "Suppression de l'exécutable $(CLAPTRAP) terminée."

re: fclean all

.PHONY: all clean fclean re