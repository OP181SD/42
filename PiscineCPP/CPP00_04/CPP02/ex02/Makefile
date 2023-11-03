# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 13:59:36 by yassine           #+#    #+#              #
#    Updated: 2023/11/03 13:59:40 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PROGRAM_NAME = Polymorphisme
CC = clang++
CPPFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -std=c++98
RM = rm -rf

SRCS = Fixed.cpp \
       main.cpp
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