/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:37:02 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/19 12:41:18 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	negative_r(t_file *file, int rx, int ry, char *str)
{
	if (rx <= 0 || ry <= 0)
	{
		write(1, "ERROR:\n-Invalid Resolution!\n", 28);
		exit_(file, str, 0);
	}
}

void	check_r(t_file *file, char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'R')
			count++;
		i++;
	}
	if (count != 1)
	{
		write(1, "ERROR:\n-Invalid Resolution!\n", 28);
		exit_(file, str, 0);
	}
}

void	resolution(t_file *file, char *line, char *str, int i)
{
	int	count_xy;
	int	count_space;

	count_space = 0;
	count_xy = 1;
	check_r(file, str);
	while (line[i])
	{
		if (line[i] == ' ')
			count_space++;
		if ((line[i] < '0' || line[i] > '9') && line[i] != 32)
		{
			write(1, "ERROR:\n-Invalid Resolution!\n", 28);
			exit_(file, str, 0);
		}
		if (line[i] == ' ' && (line[i + 1] >= '0' && line[i + 1] <= '9'))
			count_xy++;
		i++;
	}
	if (count_xy != 2 || count_space != 1)
	{
		write(1, "ERROR:\n-Invalid Resolution!\n", 28);
		exit_(file, str, 0);
	}
}
