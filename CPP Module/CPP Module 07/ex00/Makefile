# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 10:18:50 by abougrin          #+#    #+#              #
#    Updated: 2022/01/05 12:37:40 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FewFun

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