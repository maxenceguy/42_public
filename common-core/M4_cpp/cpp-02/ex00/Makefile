# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguy <mguy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:48:15 by mguy              #+#    #+#              #
#    Updated: 2024/10/30 10:19:14 by mguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed_point

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(NAME)

$(OBJ): Makefile

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
