# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 12:05:00 by abougrin          #+#    #+#              #
#    Updated: 2021/12/18 14:42:51 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Bureaucrat

SRC= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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