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

LINE1 = " ██████╗ █████╗ ██╗      █████╗ ███╗   ██╗ ██████╗ "
LINE2 = "██╔════╝██╔══██╗██║     ██╔══██╗████╗  ██║██╔════╝ "
LINE3 = "╚█████╗ ██║  ██║██║     ██║  ██║██╔██╗ ██║██║  ███╗"
LINE4 = " ╚═══██╗██║  ██║██║     ██║  ██║██║╚██╗██║██║   ██║"
LINE5 = "██████╔╝╚█████╔╝███████╗╚█████╔╝██║ ╚████║╚██████╔╝"
LINE6 = "╚═════╝  ╚════╝ ╚══════╝ ╚════╝ ╚═╝  ╚═══╝ ╚═════╝ "

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx -I/usr/X11/include
LDFLAGS = -L$(LIB_DIR) -Lminilibx -L/usr/X11/lib 
AR = ar rcs

NAME = so_long

DISPLAY = SOLONG
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/
LIB_DIR = libft
BCK_DIR = backup
ZIP = tar
ZIPFLAGS = -czvf
UNZIP = tar
UNZIPFLAGS = -xzvf

SRC_FILES = gnl/get_next_line gnl/get_next_line_utils main get_map init events draw_map check_map resolved_map end
SRC = $(foreach file,$(SRC_FILES),$(foreach dir,$(SRC_DIR),$(dir)$(file).c))
OBJ = $(foreach file,$(SRC_FILES),$(foreach dir,$(OBJ_DIR),$(dir)$(file).o))


all: $(TITLE) $(NAME)

$(TITLE):
	echo $(TITLE); 

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) > /dev/null
	echo "$(GREEN)  ✅ ${LIB_DIR}$(DEF_COLOR)"
	@make -C minilibx > /dev/null
	echo "$(GREEN)  ✅ mlx$(DEF_COLOR)"
	$(CC) -o $@ $^ -L$(LIB_DIR) -Lminilibx -L/usr/X11/lib -std=gnu99 -lft -lmlx -lXext -lX11 -lm -lbsd
	echo "$(BYellow)MAKE$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ -g3
	echo "$(GREEN)  ✅ $<$(DEF_COLOR)"

$(OBJ_DIR):
	echo "$(ORANGE)"
	echo $(LINE1)
	echo $(LINE2)
	echo $(LINE3)
	echo $(LINE4)
	echo $(LINE5)
	echo $(LINE6)
	echo "$(DEF_COLOR)"
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/gnl/

clean:
	@make clean -C $(LIB_DIR) > /dev/null
	echo "$(BGreen)  🧹 ${LIB_DIR}$(DEF_COLOR)"
	@make clean -C minilibx > /dev/null
	echo "$(BGreen)  🧹 minilibx$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	echo "$(BBLUE)CLEAN$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIB_DIR) > /dev/null
	echo "$(BGreen)  🧹 ${LIB_DIR}$(DEF_COLOR)"
	@rm -f $(NAME)
	echo "$(BBLUE)FCLEAN$(DEF_COLOR)"

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

.SILENT:

