/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:02:06 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/28 10:25:06 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "structures.h"
# include "macros.h"
# include "GNL/get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *str);

void	check_file(int fd, t_file *var, char *line);
/*
**  read_file1.c
*/
void	r_map(int *rx, int *ry, char *line, t_file *file);
void	no_texture(char **no, char *line, t_file *file);
void	so_texture(char **so, char *line, t_file *file);
void	we_texture(char **we, char *line, t_file *file);
void	ea_texture(char **ea, char *line, t_file *file);
/*
**  check_r.c
*/
void	negative_r(t_file *file, int rx, int ry, char *str);
void	check_r(t_file *file, char *str);
void	resolution(t_file *file, char *line, char *str, int i);
/*
**  read_file2.c
*/
void	sprite(char **s, char *line, t_file *file);
void	check_floor(int *f, char *line, t_file *file, char *str);
void	check_ceiling(int *c, char *line, t_file *file, char *str);
int		checkplayer(t_file *map, char *str, int x, int y);
/*
**  red_map.c
*/
void	read_map(int fd, char *line, t_file *map, int rows);
/*
**  someft.c
*/
size_t	c_strlen(char *str, int c);
char	*z_space(char *src, char *dest, int i);
int		c_atoi(int c);
float	zero_360(float angle);
/*
**  someft2.c
*/
int		columns_size(char *str, int rows);
void	initialize(t_file *file);
int		count_dig(char *str, int i);
/*
** free all
*/
void	first_exit(t_file *file);
int		last_exit(t_file *file);
int		exit_(t_file *file, char *line, int i);
void	give_it_null(t_file *file);

/*
**  draw.c
*/
void	draw_map(t_file *file);
void	draw_fc(t_file file, int i, int j);
void	rect(t_file file, int x, int y, int color);
void	rect2(t_file file, int x, int y, int color);
/*
** player_movement.c
*/
int		player_move(int key, t_file *file);
int		iswall(t_file *file, int newx, int newy, int i);

void	castrays(t_file *file);
void	ray_facing(t_file *file);

int		check_0_2(t_file file, int j, int k);
void	check_finalmap(t_file *file, char *str);
void	savemap(t_file *file, char *str, int rows, int columns);

void	h_inter(t_file *file, t_inter *inter, int con);
void	v_inter(t_file *file, t_inter *inter, int con);

void	h_dist(t_file *file, t_inter *inter, int con, int index);
void	v_dist(t_file *file, t_inter *inter, int con, int index);

void	projection_walls(t_file *file, int columnid);
void	projection_sprite(t_file *file, int columnid, int i);

void	check_sinter(t_file *file, t_inter *inter);
void	sprite_inter(t_file *file, float center_x, float center_y);
void	sort_sprite(t_file *file, int length);
void	free_sprite(t_file *file);

void	create_img(t_file *file, int fd);
void	all_xpm(t_file *file, int zero);

#endif
