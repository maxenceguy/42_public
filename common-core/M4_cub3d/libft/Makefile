# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:04:47 by mguy              #+#    #+#              #
#    Updated: 2024/07/23 16:38:29 by mguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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


PRINTF= printf
INCLUDE	= include
LIBFT	= libft
SRC_DIR	= src/
OBJ_DIR	= obj/
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
NAME = libft.a

SRC_FILES = last_char get_tab_size ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_strcmp ft_int_max ft_int_min ft_strtok ft_strcpy realloc_tab free_tab
SRC = $($(basename $(notdir $(src))), addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEP = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

all: ${NAME}

$(NAME): $(OBJ)
	make -C $(PRINTF)
	cp printf/libftprintf.a .
	mv libftprintf.a $(NAME)
	$(AR) $(NAME) $(OBJ)
	echo "$(BGreen)Libft compilation successful.$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "$(GRAY)Compilation of: $<.$(DEF_COLOR)"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ -g3

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

clean:
	make clean -C $(PRINTF)
	echo "$(BLUE)Libft clean.$(DEF_COLOR)"
	rm -f $(OBJ)
	rm -f $(DEP)

fclean: clean
	$(RM) -f $(PRINTF)/libftprintf.a
	echo "$(BLUE)Libft fclean.$(DEF_COLOR)"
	rm -f $(NAME)

re: fclean all
	echo "$(BLUE)Libft rebuild.$(DEF_COLOR)"

.PHONY: re clean fclean all

.SILENT: