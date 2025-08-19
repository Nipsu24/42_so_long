# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2025/08/19 12:57:49 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -Wunreachable-code

SRC_DIR = ./
OBJ_DIR = obj
LIBFT = ./libft
LIBMLX = ./mlx

HEADERS = -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

FILES = error_check_a.c \
		error_check_b.c \
		utils.c \
		error_messages_a.c \
		error_messages_b.c \
		valid_path.c \
		images.c \
		moves.c \
		size_pos_collect.c \
		free_and_close.c \
		main.c \

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

LINK_DIR = -L "/Users/$(USER)/.brew/opt/glfw/lib/"

ifeq ($(wildcard $(LIBMLX)/build/libmlx42.a),)
BUILD_LIBMLX = libmlx
else
BUILD_LIBMLX =
endif

all: $(BUILD_LIBMLX) $(NAME)

$(LIBMLX):
	@if [ ! -d "$(LIBMLX)" ]; then git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); fi

libmlx: $(LIBMLX)
	@if [ ! -d $(LIBMLX)/build ]; then \
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJ_FILES) $(LIBFT) $(BUILD_LIBMLX)
	make -C $(LIBFT) > /dev/null
	$(CC) $(FLAGS) $(LIBS) $(LINK_DIR) $(HEADERS) -o $(NAME) $(OBJ_FILES) -L$(LIBFT) -lft
	@echo "\033[32m$(NAME) has been built successfully!\033[0m"

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -L$(LIBFT) $(LINK_DIR) $(LIBS) -lft -g -fsanitize=address -static-libsan 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)so_long.h | $(OBJ_DIR) 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_DIR)
	

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)
	rm -rf $(LIBMLX)/build

re: 
	make fclean 
	make all

.PHONY: all clean fclean re libmlx
