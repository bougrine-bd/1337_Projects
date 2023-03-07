/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:20:01 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/28 12:09:09 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite(char **s, char *line, t_file *file)
{
	char	*str;

	str = line;
	file->element_nb++;
	if (line[0] == 'S' && (line[1] == ' ' || line[1] == '\t'))
	{
		line += 1;
		while (*line == ' ' || *line == '\t')
			line++;
		ft_strccpy(s, line, '\0');
	}
	else
	{
		write(1, "ERROR\n-Invalid Path!\n", 21);
		exit_(file, str, 0);
	}
}

void	check_color(t_file *file, char *str)
{
	int count;
	int i;

	count = 0;
	i = 1;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] == ',' && ((str[i + 1] >= '0' && str[i + 1] <= '9')
						&& (str[i - 1] >= '0' && str[i - 1] <= '9')))
						|| (str[i] == ',' && count == 2))
			count++;
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
		{
			write(1, "ERROR\n-Invalid Color!\n", 22);
			exit_(file, str, 0);
		}
		i++;
	}
	if (count != 2)
	{
		write(1, "ERROR\n-Invalid Color!\n", 22);
		exit_(file, str, 0);
	}
}

void	check_floor(int *f, char *line, t_file *file, char *str)
{
	int r;
	int g;
	int b;

	file->element_nb++;
	if (line[1] != ' ')
	{
		write(1, "ERROR\n-Invalid Color!\n", 22);
		exit_(file, str, 0);
	}
	while (*line == 'F' || *line == ' ')
		line++;
	r = ft_atoi(line);
	line += count_dig(line, 1) + 1;
	check_color(file, str);
	g = ft_atoi(line);
	line += count_dig(line, 1) + 1;
	check_color(file, str);
	b = ft_atoi(line);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		write(1, "ERROR\n-Invalid Color!\n", 22);
		exit_(file, str, 0);
	}
	*f = (r * 65536) + (g * 256) + b;
}

void	check_ceiling(int *c, char *line, t_file *file, char *str)
{
	int r;
	int g;
	int b;

	file->element_nb++;
	if (line[1] != ' ')
	{
		write(1, "ERROR\n-Invalid Color!\n", 22);
		exit_(file, str, 0);
	}
	while (*line == 'C' || *line == ' ')
		line++;
	r = ft_atoi(line);
	line += count_dig(line, 1) + 1;
	check_color(file, str);
	g = ft_atoi(line);
	line += count_dig(line, 1) + 1;
	check_color(file, str);
	b = ft_atoi(line);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		write(1, "ERROR\n-Invalid Color!\n", 22);
		exit_(file, str, 0);
	}
	*c = (r * 65536) + (g * 256) + b;
}

int		checkplayer(t_file *map, char *str, int x, int y)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			x = -1;
			y++;
		}
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			map->player->x = (x + .5) * TILE_SIZE;
			map->player->y = (y + .5) * TILE_SIZE;
		}
		x++;
		i++;
	}
	return (1);
}
