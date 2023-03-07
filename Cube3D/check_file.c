/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:37:08 by abougrin          #+#    #+#             */
/*   Updated: 2020/12/07 12:24:09 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	extra_lines(t_file *file, char *line, int fd)
{
	if ((line[0] >= '0' && line[0] <= '9') || line[0] == ' ')
		read_map(fd, line, file, 1);
	else if (line[0])
	{
		write(1, "ERROR\n-Invalid file!\n", 21);
		exit_(file, line, 0);
	}
}

void	check_file(int fd, t_file *file, char *line)
{
	while ((get_next_line(fd, &line)) == 1)
	{
		if (line[0] == 'R')
			r_map(&WIN_X, &WIN_Y, line, file);
		else if (line[0] == 'N' && line[1] == 'O')
			no_texture(&NO, line, file);
		else if (line[0] == 'S' && line[1] == 'O')
			so_texture(&SO, line, file);
		else if (line[0] == 'W' && line[1] == 'E')
			we_texture(&WE, line, file);
		else if (line[0] == 'E' && line[1] == 'A')
			ea_texture(&EA, line, file);
		else if (line[0] == 'S')
			sprite(&SP, line, file);
		else if (line[0] == 'F')
			check_floor(&F, line, file, line);
		else if (line[0] == 'C')
			check_ceiling(&C, line, file, line);
		else if ((line[0] >= '0' && line[0] <= '9') || line[0])
		{
			extra_lines(file, line, fd);
			break ;
		}
		free(line);
	}
}
