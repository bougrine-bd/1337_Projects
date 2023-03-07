# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 15:08:14 by abougrin          #+#    #+#              #
#    Updated: 2021/12/12 18:09:06 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Polymorphism

SRC= main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(SRC)
	@clang++  -c $(SRC) -std=c++98
	@clang++  -o $(NAME) $(SRC) -std=c++98

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all