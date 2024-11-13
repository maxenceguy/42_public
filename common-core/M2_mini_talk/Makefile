# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 12:19:53 by mguy              #+#    #+#              #
#    Updated: 2024/01/29 12:46:14 by mguy             ###   ########.fr        #
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



NAMESV	= server
NAMECL	= client
INCLUDE	= include
LIBFT	= libft
SRC_DIR	= ./
OBJ_DIR	= obj/
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR = ar rcs

SRC_FILES_SV = server
SRCSV = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_SV)))
OBJSV = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_SV)))

SRC_FILES_CL = client
SRCCL = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_CL)))
OBJCL = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_CL)))

all: $(NAMESV) $(NAMECL)

$(NAMESV): $(OBJSV)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSV) -o $(NAMESV) libft/libft.a -g3
	echo "$(BGreen)Server: ok$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "$(GRAY)Compilation of: $<.$(DEF_COLOR)"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ -g3

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAMECL): $(OBJCL)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJCL) -o $(NAMECL) libft/libft.a -g3
	echo "$(BGreen)Client: ok$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "$(GRAY)Compilation of: $<.$(DEF_COLOR)"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ -g3

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_DIR)
	echo "$(BLUE)Clean libft & .o$(DEF_COLOR)"

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAMESV)
	rm -f $(NAMECL)
	echo "$(BLUE)Flcean$(DEF_COLOR)"
	

re: fclean all
	echo "$(BLUE)Rebuild$(DEF_COLOR)"

.PHONY: re clean fclean all

.SILENT:

