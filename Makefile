# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:40:14 by mkaruvan          #+#    #+#              #
#    Updated: 2023/06/26 08:34:44 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.o

SERVER = server.o

SRC = client.c server.c

CLIENT_NAME = client

SERVER_NAME = server

LIBFT_DIR = libft

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

$(CLIENT_NAME): $(CLIENT) $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)compiling client...$(EOC)"
	$(CC) $(CFLAGS) $(CLIENT) -o $@ $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)client build completed...$(EOC)"
$(SERVER_NAME): $(SERVER) $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)compiling server...$(EOC)"
	$(CC) $(CFLAGS) $(SERVER) -o $@ $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)server build completed...$(EOC)"

$(LIBFT) :
	@make -C $(LIBFT_DIR)

clean:
	@echo "$(RED)removing object files...$(EOC)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) server.o client.o server client
fclean:
	@echo "$(RED)removing build files...$(EOC)"
	@make -C $(LIBFT_DIR) fclean
	@make -C ./ clean
re:
	@make fclean
	@make all
norm:
	@norminette -R CheckForbiddenSourceHeader *.c

.PHONY:	all bonus clean fclean re norm
