# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 10:26:34 by abougrin          #+#    #+#              #
#    Updated: 2019/12/30 16:35:24 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_check.c ft_conv0.c ft_conv1.c ft_flagz.c ft_helpers.c \
	ft_isalpha.c ft_isdigit.c ft_itoa.c ft_printf.c ft_putnbr.c ft_someft.c \
	ft_someft2.c ft_writer.c 

OBJ = ft_atoi.o ft_check.o ft_conv0.o ft_conv1.o ft_flagz.o ft_helpers.o \
	ft_isalpha.o ft_isdigit.o ft_itoa.o ft_printf.o ft_putnbr.o ft_someft.o \
	ft_someft2.o ft_writer.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
