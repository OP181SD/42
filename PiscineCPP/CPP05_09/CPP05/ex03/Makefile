# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yassine <yassine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 16:09:22 by yassine           #+#    #+#              #
#    Updated: 2024/01/08 16:35:22 by yassine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME = Bureaucrat

CC = clang++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRCS = Bureaucrat.cpp \
		AForm.cpp \
		Intern.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		main.cpp 
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