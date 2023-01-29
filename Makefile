# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:40:14 by mkaruvan          #+#    #+#              #
#    Updated: 2022/04/12 14:40:16 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.o

SERVER = server.o

SRC = client.c server.c

CLIENT_NAME = client

SERVER_NAME = server

LIBFT_DIR = libft

FT_PRINTF = libftprintf.a

FT_PRINTF_DIR = libft/ft_printf

LIBFT = libft.a

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(OBJ)
	@echo "$(WHT)compiling minitalk...$(EOC)"
	$(CC) $(CFLAGS) $(CLIENT) -o $@ $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF)
	@echo "$(WHT)minitalk build completed...$(EOC)"
$(SERVER_NAME): $(OBJ)
	@echo "$(WHT)compiling minitalk...$(EOC)"
	$(CC) $(CFLAGS) $(SERVER) -o $@ $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF)
	@echo "$(WHT)minitalk build completed...$(EOC)"
$(LIBFT) : 
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)

clean:
	@echo "$(WHT)removing object files...$(EOC)"
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@$(RM) server.o client.o server client
fclean:
	@echo "$(WHT)removing build files...$(EOC)"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C ./ clean
re:
	@make fclean
	@make all
norm:
	@norminette -R CheckForbiddenSourceHeader *.c

.PHONY:	all bonus clean fclean re norm
