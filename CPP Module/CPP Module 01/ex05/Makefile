# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 10:54:06 by abougrin          #+#    #+#              #
#    Updated: 2021/12/03 10:54:07 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= karen

SRC= main.cpp Karen.cpp
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