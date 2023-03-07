/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:37:40 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/27 10:23:29 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	r_map(int *rx, int *ry, char *line, t_file *file)
{
	int		count;
	char	*str;

	str = line;
	file->element_nb++;
	if (line[1] != ' ')
	{
		write(1, "ERROR:\n-Invalid Resolution!\n", 28);
		exit_(file, str, 0);
	}
	while (*line == 'R' || *line == ' ')
		line++;
	resolution(file, line, str, 0);
	count = count_dig(line, 0);
	*rx = ft_atoi(line);
	if (*rx > MAX_WIDTH || count >= 5)
		*rx = MAX_WIDTH;
	line += count_dig(line, 1);
	count = count_dig(line, 0);
	*ry = ft_atoi(line);
	if (*ry > MAX_HIGHT || count >= 5)
		*ry = MAX_HIGHT;
	negative_r(file, *rx, *ry, str);
}

void	no_texture(char **no, char *line, t_file *file)
{
	char	*str;

	file->nb_line = 1;
	str = line;
	file->element_nb++;
	if (line[2] == ' ' || line[2] == '\t')
	{
		line += 2;
		while (*line == ' ' || *line == '\t')
			line++;
		ft_strccpy(no, line, '\0');
	}
	else
	{
		write(1, "ERROR\n-Invalid Path!\n", 21);
		exit_(file, str, 0);
	}
}

void	so_texture(char **so, char *line, t_file *file)
{
	char	*str;

	str = line;
	file->element_nb++;
	if (line[2] == ' ' || line[2] == '\t')
	{
		line += 2;
		while (*line == ' ' || *line == '\t')
			line++;
		ft_strccpy(so, line, '\0');
	}
	else
	{
		write(1, "ERROR\n-Invalid Path!\n", 21);
		exit_(file, str, 0);
	}
}

void	we_texture(char **we, char *line, t_file *file)
{
	char	*str;

	str = line;
	file->element_nb++;
	if (line[2] == ' ' || line[2] == '\t')
	{
		line += 2;
		while (*line == ' ' || *line == '\t')
			line++;
		ft_strccpy(we, line, '\0');
	}
	else
	{
		write(1, "ERROR\n-Invalid Path!\n", 21);
		exit_(file, str, 0);
	}
}

void	ea_texture(char **ea, char *line, t_file *file)
{
	char	*str;

	str = line;
	file->element_nb++;
	if (line[2] == ' ' || line[2] == '\t')
	{
		line += 2;
		while (*line == ' ' || *line == '\t')
			line++;
		ft_strccpy(ea, line, '\0');
	}
	else
	{
		write(1, "ERROR\n-Invalid Path!\n", 21);
		exit_(file, str, 0);
	}
}
