/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someft2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:04:56 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/19 14:00:37 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_file *file)
{
	if (file->player->direction == 'N')
		file->player->angle = 270;
	else if (file->player->direction == 'S')
		file->player->angle = 90;
	else if (file->player->direction == 'W')
		file->player->angle = 180;
	else if (file->player->direction == 'E')
		file->player->angle = 0;
}

int		columns_size(char *str, int rows)
{
	int larger;

	larger = 0;
	while (rows != 1)
	{
		if (larger < (int)c_strlen(str, '\n'))
			larger = c_strlen(str, '\n');
		str += c_strlen(str, '\n') + 1;
		rows--;
	}
	if (larger < (int)c_strlen(str, '\0'))
		larger = c_strlen(str, '\0');
	return (larger);
}

int		count_dig(char *str, int i)
{
	int count;

	count = 0;
	while (*str == '0' || *str == 32)
	{
		if (*str == '0' && i == 0)
			str++;
		else if (*str == '0' && i == 1)
			break ;
		else
			str++;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		count++;
		str++;
	}
	return (count);
}
