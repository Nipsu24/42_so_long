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

FILES = error_check.c \
		utils.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror 

$(NAME): $(OBJ_FILES) $(LIBFT)
	make -C $(LIBFT) > /dev/null
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIBFT) -lft
	@echo "\033[32m$(NAME) has been built successfully!\033[0m"

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -L$(LIBFT) -lft -g -fsanitize=address -static-libsan 

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

