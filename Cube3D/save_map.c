/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:12:13 by abougrin          #+#    #+#             */
/*   Updated: 2020/12/10 10:12:03 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_0_2(t_file file, int j, int k)
{
	if ((MAP[k][j] == 0 || MAP[k][j] == 2) &&
		((MAP[k][j + 1] != 1 && MAP[k][j + 1] != 0 && MAP[k][j + 1] != 2)
		|| (MAP[k][j - 1] != 1 && MAP[k][j - 1] != 0 && MAP[k][j - 1] != 2)
		|| (MAP[k + 1][j] != 1 && MAP[k + 1][j] != 0 && MAP[k + 1][j] != 2)
		|| (MAP[k - 1][j] != 1 && MAP[k - 1][j] != 0 && MAP[k - 1][j] != 2)))
	{
		return (1);
	}
	return (0);
}

void	check_finalmap(t_file *file, char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == '\n')
		{
			j = 0;
			k++;
			i++;
		}
		if (check_0_2(*file, j, k) == 1)
		{
			write(1, "Error\n-Invalid Map!\n", 20);
			free(file->str_add);
			exit_(file, str, 0);
		}
		j++;
		i++;
	}
}

void	savemap(t_file *file, char *str, int rows, int columns)
{
	int i;
	int j;
	int k;

	file->map = malloc(rows * sizeof(int *));
	file->map[0] = malloc(columns * sizeof(int));
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\n' && i++)
		{
			j = 0;
			file->map[++k] = malloc(columns * sizeof(int));
			while (j < columns)
				file->map[k][j++] = 8;
			j = 0;
		}
		file->map[k][j] = str[i] == 'N' || str[i] == 'S' || str[i] == 'E'
			|| str[i] == 'W' ? 0 : c_atoi(str[i]);
		j++;
		i++;
	}
	check_finalmap(file, str);
}
