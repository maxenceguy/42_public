# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermolo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 15:51:50 by mguy              #+#    #+#              #
#    Updated: 2023/08/30 19:33:58 by alermolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc

CFLAGS= -Wall -Werror -Wextra

HEADER = includes/ft.h

SRC = srcs/main.c				\
	  	srcs/display_map.c		\
		srcs/ft_split.c			\
		srcs/ft_strlen.c		\
		srcs/parse_map.c		\
		srcs/find_square.c		\
		srcs/free.c				\
		srcs/read_stdin.c

OBJ = $(SRC:.c=.o)

NAME = bsq

all: ${NAME}

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I ${HEADER} -c $< -o $@

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f srcs/*.o
	rm -f raw_map

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all%
