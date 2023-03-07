# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 11:54:20 by abougrin          #+#    #+#              #
#    Updated: 2022/02/05 13:47:54 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

SRC= main.cpp
OBJ= $(SRC:.cpp=.o)
FLAG= -Wall -Wextra -Werror
STDLIB= -std=c++98

all: $(NAME)
$(NAME): $(SRC)
	@clang++ $(SRC) $(FLAG) $(STDLIB) -c
	@clang++ $(SRC) $(FLAG) $(STDLIB) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all