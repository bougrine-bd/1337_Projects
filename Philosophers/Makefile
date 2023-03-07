# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 14:25:18 by abougrin          #+#    #+#              #
#    Updated: 2022/10/29 06:29:33 by abougrin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/philosophers.c src/inital_vals.c src/activities.c src/tools.c
OBJ = philosophers.o inital_vals.o activities.o tools.o

all: $(NAME)

$(NAME) : $(SRC)
	@gcc -Wall -Wextra -Werror $(SRC) -c 
	@gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)
clean: 
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all