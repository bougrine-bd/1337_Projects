/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:01:15 by abougrin          #+#    #+#             */
/*   Updated: 2020/12/10 09:43:16 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkmap(t_file *file, char *str, int i, int row)
{
	while (str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			row++;
			if ((str[i] == '\n' && ((str[i - 1] != '1' && str[i - 1] != ' ')
				|| (str[i + 1] != '1' && str[i + 1] != ' '))))
				return (0);
			while (str[++i] == ' ')
				if (str[i] == '\n' || !str[i + 1])
					return (0);
		}
		if (row == file->rows - 1)
			while (str[i + 1] && i++)
				if (str[i] != '1' && str[i] != ' ')
					return (0);
		i++;
	}
	return (1);
}

int		check_news(char *str, t_file *map, int i)
{
	int count;

	count = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			map->player->direction = str[i];
			count++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '2'
		&& str[i] != '\n' && str[i] != ' ' && (str[i] != 'N'
		&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W'))
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_file *file, char *str, char *dest)
{
	if ((checkmap(file, str, 0, 0) && check_news(str, file, 0)
		&& checkplayer(file, str, -1, 0)) == 1)
	{
		file->str_add = str;
		str = z_space(str, dest, 0);
		savemap(file, str, file->rows, file->columns);
		free(str);
	}
	else
	{
		write(1, "Error\n-Invalid Map!\n", 20);
		exit_(file, str, 0);
	}
}

void	read_map(int fd, char *line, t_file *file, int rows)
{
	int		ret;
	char	*str;

	if (file->element_nb != 8)
	{
		write(1, "Error\n-Invalid file\n", 20);
		exit_(file, line, 0);
	}
	str = NULL;
	str = ft_strjoin(str, line);
	free(line);
	while ((ret = get_next_line(fd, &line)) != -1)
	{
		str = ft_strjoin(str, "\n");
		str = ft_strjoin(str, line);
		rows++;
		free(line);
		if (ret == 0)
			break ;
	}
	str = ft_strjoin(str, "\0");
	file->rows = rows;
	file->columns = columns_size(str, file->rows);
	check_map(file, str, NULL);
	free(str);
}
