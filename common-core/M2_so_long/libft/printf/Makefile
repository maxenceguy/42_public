# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:04:47 by mguy              #+#    #+#              #
#    Updated: 2023/11/24 23:42:37 by mguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
INCLUDE	= include
LIBFT	= libft
SRC_DIR	= src/
OBJ_DIR	= obj/
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs


DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

BBlack		= \033[1;30m
BRed		= \033[1;31m
BGreen		= \033[1;32m
BYellow		= \033[1;33m
BBlue		= \033[1;34m
BPurple		= \033[1;35m
BCyan		= \033[1;36m
BWhite		= \033[1;37m



SRC_FILES = ft_printf ft_putchar ft_putstr ft_hexa ft_utoa ft_pointer
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


all: ${NAME}

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	echo "$(BLUE)Printf compilation successful.$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "$(GRAY)Compilation of: $<.$(DEF_COLOR)"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	echo "$(BLUE)Printf clean.$(DEF_COLOR)"

fclean: clean
	rm -f $(NAME)
	echo "$(BLUE)Printf fclean.$(DEF_COLOR)"
	

re: fclean all
	echo "$(BLUE)Printf rebuild.$(DEF_COLOR)"

.PHONY: re clean fclean all

.SILENT:

