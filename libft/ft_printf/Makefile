# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 04:47:02 by mkaruvan          #+#    #+#              #
#    Updated: 2022/04/12 12:15:31 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putchar.c	ft_putint.c	ft_putunint.c ft_printf.c	ft_putaddr.c \
   	   ft_puthex.c	ft_putstr.c ft_puthexcap.c

OBJS = $(SRCS:.c=.o)

NAME =	libftprintf.a

CFLAGS	= -Wall -Werror -Wextra

all	: $(NAME)

$(NAME)	: $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all
