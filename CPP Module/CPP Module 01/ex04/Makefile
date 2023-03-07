# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 10:53:45 by abougrin          #+#    #+#              #
#    Updated: 2021/12/04 11:46:07 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= replace

SRC= main.cpp
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