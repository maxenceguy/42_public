# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:16:53 by mguy              #+#    #+#              #
#    Updated: 2024/09/26 17:40:18 by mguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiling flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -ffast-math 

# Name of your executable
NAME = cub3D

# Directories
SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = ./includes
MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
GNL_DIR = ./get_next_line
MAKE = make

# Source and object files
SRC_FILES = main.c free_all.c free_all2.c\
			parsing/parse.c parsing/utils.c parsing/get_map.c parsing/get_elements.c parsing/check_validity.c \
			simulation/render.c simulation/move.c simulation/init.c simulation/vector.c simulation/init_textures.c simulation/utils.c simulation/ray_cast.c simulation/render_3d.c simulation/draw.c \
			simulation/move_utils.c 

GNL_FILES = get_next_line.c get_next_line_utils.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(GNL_DIR)/,$(GNL_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o) $(GNL_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

# MiniLibX and libft flags
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT = -L$(LIBFT_DIR) -lft
MINILIBX_DIR = minilibx-linux

# Include directories
INC = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)

# Make sure to create necessary directories
OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/parsing $(OBJ_DIR)/simulation $(OBJ_DIR)/get_next_line

all: $(MINILIBX_DIR) $(OBJ_DIRS) $(NAME)

$(MINILIBX_DIR):
	if [ ! -d "$(MINILIBX_DIR)" ]; then \
		echo "Dossier $(MINILIBX_DIR) non trouvé, clonage de la minilibx."; \
		git clone git@github.com:42Paris/minilibx-linux.git minilibx-linux; \
		cd minilibx-linux && ./configure && cd ..; \
	fi

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)  # Compile MiniLibX
	$(MAKE) -C $(LIBFT_DIR)  # Compile libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) -o $(NAME) $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Nettoyer les fichiers objets et les sous-répertoires
clean:
	rm -rf $(OBJ_DIR)  # Supprimer le dossier obj
	$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "$(MINILIBX_DIR)" ]; then \
		$(MAKE) -C $(MLX_DIR) clean; \
	fi

# Nettoyer tout, y compris l'exécutable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ -d "$(MINILIBX_DIR)" ]; then \
		$(MAKE) -C $(MLX_DIR) clean; \
		rm -rf $(MINILIBX_DIR); \
	fi

re: fclean all

.PHONY: all clean fclean re
