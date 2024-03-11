# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2024/03/06 16:00:32 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
SRC_DIR = ./
OBJ_DIR = obj
LIBFT = ./libft
MLX_DIR = ./mlx

FILES = error_check.c \
		utils.c \
		main.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

INCLUDES = -I/opt/X11/include -Imlx

MLX_LIB = $(MLX_DIR)/libmlx_Darwin.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror 

$(NAME): $(OBJ_FILES) $(LIBFT)
	make -C $(LIBFT) > /dev/null
	make -C$(MLX_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES) $(MLX_FLAGS) -L$(LIBFT) -lft
	@echo "\033[32m$(NAME) has been built successfully!\033[0m"

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -L$(LIBFT) -lft -g -fsanitize=address -static-libsan 

all: $(MLX_LIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) 
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

