# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 04:47:02 by mkaruvan          #+#    #+#              #
#    Updated: 2022/03/03 09:18:23 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putchar.c	ft_putint.c	ft_putunint.c ft_printf.c	ft_putaddr.c \
   	   ft_puthex.c	ft_putstr.c ft_puthexcap.c

OBJS = $(SRCS:.c=.o)

NAME =	libftprintf.a

CFLAGS	= -Wall -Werror -Wextra

$(NAME)	: $(OBJS)
		ar rcs $(NAME) $(OBJS)

all	: $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all
