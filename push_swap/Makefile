# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 12:33:05 by abougrin          #+#    #+#              #
#    Updated: 2021/07/01 17:49:05 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker

SRC = push_swap.c errors.c instractions.c instractions_p.c operations_p.c operations.c sorting.c
OBJ = push_swap.o errors.o instractions.o instractions_p.o operations_p.o operations.o sorting.o

SRCB = checker.c errors.c instractions.c instractions_p.c operations_p.c operations.c sorting.c
OBJB = checker.o errors.o instractions.o instractions_p.o operations_p.o operations.o sorting.o

all: $(NAME)
$(NAME): $(SRC)
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME) 
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

bonus: $(NAMEB)
$(NAMEB): $(SRCB)
	gcc -Wall -Werror -Wextra -c $(SRCB)
	gcc -Wall -Werror -Wextra $(OBJB) -o $(NAMEB) 
