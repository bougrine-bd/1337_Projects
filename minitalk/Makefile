# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 18:27:07 by abougrin          #+#    #+#              #
#    Updated: 2021/06/22 11:14:55 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAMEC = client
NAMEB = server_bonus
NAMEBC = client_bonus

SRC = server.c
OBJ = server.o

SRCB = server_bonus.c
OBJB = server_bonus.o

SRCC = client.c
OBJC = client.o

SRCBC = client_bonus.c
OBJBC = client_bonus.o

all: $(NAME) $(NAMEC)
$(NAME): $(SRC)
	gcc	-Wall -Wextra -Werror -c $(SRC)
	gcc	-Wall -Wextra -Werror $(OBJ) -o $(NAME)
$(NAMEC): $(SRCC)
	gcc	-Wall -Wextra -Werror -c $(SRCC)
	gcc	-Wall -Wextra -Werror $(OBJC) -o $(NAMEC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAMEC) $(NAMEB) $(NAMEBC)

re: fclean all

bonus: $(NAMEB) $(NAMEBC)
$(NAMEB): $(SRCB)
	gcc	-Wall -Wextra -Werror -c $(SRCB)
	gcc	-Wall -Wextra -Werror $(OBJB) -o $(NAMEB)
$(NAMEBC): $(SRCBC)
	gcc	-Wall -Wextra -Werror -c $(SRCBC)
	gcc	-Wall -Wextra -Werror $(OBJBC) -o $(NAMEBC)
	