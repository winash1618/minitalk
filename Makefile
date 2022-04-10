CLIENT = client.c
SERVER = server.c
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

OBJ = server client

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf


all: 
	@echo "$(WHT)Compiling libft...$(EOC)"
	@make -C $(LIBFT_DIR)
	@echo "$(WHT)libft build completed...$(EOC)"
	@echo "$(WHT)Compiling ft_printf...$(EOC)"
	@make -C $(FT_PRINTF_DIR)
	@echo "$(WHT)ft_printf build completed...$(EOC)"
	@echo "$(WHT)compiling minitalk...$(EOC)"
	@$(CC) $(FLAGS) $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF) $(CLIENT) -o $(CLIENT_NAME) 
	@$(CC) $(FLAGS) $(SERVER) $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF) -o $(SERVER_NAME)
	@echo "$(WHT)minitalk build completed...$(EOC)"
clean:
	@echo "$(WHT)removing object files...$(EOC)"
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@$(RM) server client
fclean:
	@echo "$(WHT)removing build files...$(EOC)"
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C ./ clean
re:
	@make fclean
	@make all