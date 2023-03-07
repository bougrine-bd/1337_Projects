# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 10:52:47 by abougrin          #+#    #+#              #
#    Updated: 2021/12/03 13:53:02 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Zombie

SRC= main.cpp Zombie.cpp ZombieHorde.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(SRC)
	@clang++ -Wall -Wextra -Werror -c $(SRC) -std=c++98
	@clang++ -Wall -Wextra -Werror -o $(NAME) $(SRC) -std=c++98

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all