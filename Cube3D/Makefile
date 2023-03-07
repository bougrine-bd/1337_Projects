# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 13:25:20 by abougrin          #+#    #+#              #
#    Updated: 2020/11/25 10:20:56 by abougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLX = libmlx.a -framework OpenGL -framework AppKit
HEADERS = cub3d.h macros.h structures.h
SRC = cub3d.c save_img.c check_file.c check_r.c draw_fc.c drawing_sprite.c drawing_walls.c\
		free_all.c player_movement.c raycast.c read_file1.c read_file2.c\
		read_map.c save_map.c someft1.c someft2.c GNL/get_next_line.c\
		GNL/get_next_line_utils.c ft_atoi.c ft_memcpy.c
OBJ = cub3d.o save_img.o check_file.o check_r.o draw_fc.o drawing_sprite.o drawing_walls.o\
		free_all.o player_movement.o raycast.o read_file1.o read_file2.o\
		read_map.o save_map.o someft1.o someft2.o get_next_line.o\
		get_next_line_utils.o ft_atoi.o ft_memcpy.o

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(MLX)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all