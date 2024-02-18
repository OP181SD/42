# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 09:39:56 by yassine           #+#    #+#              #
#    Updated: 2024/02/18 12:40:20 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME = ircserv

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRCS = src/main.cpp \
	   src/Clients/Client.cpp 
OBJS = $(SRCS:%.cpp=%.o)

INCLUDES_DIR = includes 

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(PROGRAM_NAME)
	@echo "Compilation terminée. L'exécutable $(PROGRAM_NAME) a été créé."

.cpp.o:
	@$(CC) $(CPPFLAGS) -I$(INCLUDES_DIR) -c $< -o $@
	@echo "Compiling $<."

clean:
	@$(RM) $(OBJS)
	@echo "Suppression des fichiers objets terminée."

fclean: clean
	@$(RM) $(PROGRAM_NAME)
	@echo "Suppression de l'exécutable $(PROGRAM_NAME) terminée."

re: fclean all

.PHONY: all clean fclean re
