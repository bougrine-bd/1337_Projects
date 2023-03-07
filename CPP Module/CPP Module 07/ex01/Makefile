# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 11:06:07 by abougrin          #+#    #+#              #
#    Updated: 2022/01/04 18:17:17 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Iter

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