/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:36:06 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/10 10:50:18 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_fc(t_file file, int i, int j)
{
	while (i < file.win_y / 2)
	{
		j = 0;
		while (j < file.win_x)
		{
			file.pxl_clr[i * file.win_x + j] = file.ceilling;
			j++;
		}
		i++;
	}
	while (i < file.win_y)
	{
		j = 0;
		while (j < file.win_x)
		{
			file.pxl_clr[i * file.win_x + j] = file.floor;
			j++;
		}
		i++;
	}
}
