# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 14:52:45 by mguy              #+#    #+#              #
#    Updated: 2024/10/25 16:08:18 by mguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -I$(INC)
INC = includes
NAME = zombie

FILES = srcs/main srcs/Zombie srcs/zombieHorde
SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ) : Makefile

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP)


fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re