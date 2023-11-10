# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 17:43:49 by yassine           #+#    #+#              #
#    Updated: 2023/11/10 17:45:01 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAMME NAME = Polymorphism

CC = clang++

INCLUDES = include

CPPFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -std=c++98

RM = rm -rf

SRCS = 	   src/main.cpp \
           src/Dog.cpp \
           src/Cat.cpp \
           src/Animal.cpp \
           src/Brain.cpp \
           src/WrongAnimal.cpp \
           src/WrongCat.cpp 
OBJS = $(SRCS:%.cpp=%.o)

all: $(PROGRAMME NAME)

$(PROGRAMME NAME): $(OBJS)
        @$(CC) $(CPPFLAGS) $(OBJS) -o $(PROGRAMME NAME)
        @echo "Compilation terminée. L'exécutable $(PROGRAMME NAME) a été créé."

.cpp.o:
        @$(CC) $(CPPFLAGS) -c $< -o $@
        @echo "Compiling $<."

clean:
        @$(RM) $(OBJS)
        @echo "Suppression des fichiers objets terminée." 

fclean: clean
        @$(RM) $(PROGRAMME NAME)
        @echo "Suppression de l'exécutable $(PROGRAMME NAME) terminée."

re: fclean all

.PHONY: all clean fclean re% 