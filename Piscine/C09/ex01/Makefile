# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 19:50:11 by yasaidi           #+#    #+#              #
#    Updated: 2022/11/14 20:40:16 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a


SRCS	=	srcs/ft_putstr.c \
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c \
			srcs/ft_swap.c \
			srcs/ft_putchar.c

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
LIBC 	=	ar -rc
CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
			${CC} ${CFLAGS} -c -I./includes $< -o $@


 ${NAME} :  $(OBJS)
					ar rc  $(NAME) $(OBJS)

all	:  ${NAME} 

clean	:
			rm -f  $(OBJS)

fclean	: clean
			rm -rf $(NAME)

re	:	fclean all
