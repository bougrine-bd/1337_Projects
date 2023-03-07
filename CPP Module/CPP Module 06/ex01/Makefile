# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 12:26:01 by abougrin          #+#    #+#              #
#    Updated: 2022/01/03 11:09:52 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ReinterpretCast

SRC= main.cpp Data.cpp
OBJ= $(SRC:.cpp=.o)
FLAG= -Wall -Wextra -Werror
STDLIB= -std=c++98

all: $(NAME)
$(NAME): $(SRC)
	@clang++ $(FLAG) -c $(SRC) $(STDLIB)
	@clang++ $(FLAG) -o $(NAME) $(SRC) $(STDLIB)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all