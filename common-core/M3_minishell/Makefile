# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:32:59 by mguy              #+#    #+#              #
#    Updated: 2024/08/01 00:22:49 by mguy             ###   ########.fr        #
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
ORANGE		= \033[38;5;214m

BBlack		= \033[1;30m
BRed		= \033[1;31m
BGreen		= \033[1;32m
BYellow		= \033[1;33m
BBlue		= \033[1;34m
BPurple		= \033[1;35m
BCyan		= \033[1;36m
BWhite		= \033[1;37m

LINE1 = "███╗   ███╗██████╗ ███╗   ██╗██████╗  ██████╗██╗  ██╗███████╗██╗     ██╗     "
LINE2 = "████╗ ████║╚═██╔═╝ ████╗  ██║╚═██╔═╝ ██╔════╝██║  ██║██╔════╝██║     ██║     "
LINE3 = "██╔████╔██║  ██║   ██╔██╗ ██║  ██║   ╚█████╗ ███████║███████╗██║     ██║     "
LINE4 = "██║╚██╔╝██║  ██║   ██║╚██╗██║  ██║    ╚═══██╗██╔══██║██╔════╝██║     ██║     "
LINE5 = "██║ ╚═╝ ██║██████╗ ██║ ╚████║██████╗ ██████╔╝██║  ██║███████╗███████╗███████╗"
LINE6 = "╚═╝     ╚═╝╚═════╝ ╚═╝  ╚═══╝╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
LDFLAGS = -L$(LIB_DIR)
AR = ar rcs

NAME = minishell

DISPLAY = MINISHELL
SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = include/
LIB_DIR = libft/
BCK_DIR = backup
ZIP = tar
ZIPFLAGS = -czvf
UNZIP = tar
UNZIPFLAGS = -xzvf

EXEC = command ft_cd ft_echo ft_export ft_pwd ft_unset builtins ft_exit redirect exec_command ft_echo_utils
ENV = get_env
LEXER_PARSER = demote_tokens expander get_next_token tokenizer redirection_parser heredoc heredoc_exec token_to_command token_to_command_bis joiner heredoc_expand_last_process
LEXER_PARSER_UTILS = pop_node token_to_command_utils
TOOLS = ft_readline free_cmd path_tools list_to_tab
OTHER = main

SRC = $(addsuffix .c, $(addprefix srcs/exec/, $(EXEC))) \
	  $(addsuffix .c, $(addprefix srcs/env/, $(ENV))) \
	  $(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS))) \
	  $(addsuffix .c, $(addprefix srcs/, $(OTHER))) \
	  $(addsuffix .c, $(addprefix srcs/lexer_parser/, $(LEXER_PARSER))) \
	  $(addsuffix .c, $(addprefix srcs/lexer_parser_utils/, $(LEXER_PARSER_UTILS)))


# OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(EXEC))) \
# 	  $(addsuffix .o, $(addprefix $(OBJ_DIR), $(ENV))) \
# 	  $(addsuffix .o, $(addprefix $(OBJ_DIR), $(TOOLS))) \
# 	  $(addsuffix .o, $(addprefix $(OBJ_DIR), $(OTHER))) \

# DEP = $(addsuffix .d, $(addprefix $(OBJ_DIR), $(EXEC))) \
# 	  $(addsuffix .d, $(addprefix $(OBJ_DIR), $(ENV))) \
# 	  $(addsuffix .d, $(addprefix $(OBJ_DIR), $(TOOLS))) \
# 	  $(addsuffix .d, $(addprefix $(OBJ_DIR), $(OTHER))) \


OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(LIB_DIR) > /dev/null
	$(CC) $(LDFLAGS) -o $@ $^ -lft -lncurses -lreadline
	@echo $(LINE1)
	@echo $(LINE2)
	@echo $(LINE3)
	@echo $(LINE4)
	@echo $(LINE5)
	@echo $(LINE6)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ -g3

-include $(DEP)

clean:
	@make clean -C $(LIB_DIR) > /dev/null
	@echo "🧹 ${LIB_DIR}"
	rm -rf $(OBJ)
	rm -rf $(DEP)
	@echo "CLEAN"

fclean: clean
	@make fclean -C $(LIB_DIR) > /dev/null
	@echo "🧹 ${LIB_DIR}"
	@rm -f $(NAME)
	@echo "FCLEAN"

re: fclean all

archive:
	echo "Archiving the source files..."
	mkdir -p $(BCK_DIR)
	$(ZIP) $(ZIPFLAGS) $(BCK_DIR)/backup_$(shell date +'%Y%m%d%H%M%S').tar.gz .
	echo "Archive file generated."

revert:
	$(eval LATEST_BACKUP := $(shell ls -1t $(BCK_DIR)/*.tar.gz | head -n 1))
	if [ -n "$(LATEST_BACKUP)" ]; then
		$(UNZIP) $(UNZIPFLAGS) "$(LATEST_BACKUP)" -C .;
		echo "Project reverted from the backup.";
	else
		echo "No backups found.";
	fi

num:
	echo "Current version number: $(shell ls -1 $(BCK_DIR) | wc -l)"

delete:
	echo "Deleting the last backup..."
	$(eval LATEST_BACKUP := $(shell ls -1t $(BCK_DIR)/*.tar.gz | head -n 1))
	if [ -n "$(LATEST_BACKUP)" ]; then
		rm -f "$(LATEST_BACKUP)";
		echo "Last backup deleted.";
	else
		rm -rf $(BCK_DIR);
		echo "No backups found.";
	fi

.PHONY: display_word all clean fclean re archive revert num delete
