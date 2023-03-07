/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:36:20 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/25 10:10:17 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_no(t_file *file, float wall_height, int columnid)
{
	int pxl;
	int half;
	int i;

	file->rcast->oset = file->rcast->oset * 100 / TILE_SIZE;
	file->rcast->x_text = (int)((file->rcast->oset * NO_WIDTH) / 100);
	half = wall_height / 2;
	i = 0;
	while (i < half && i <= WIN_Y / 2)
	{
		file->rcast->oset = (int)((half + i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * NO_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * NO_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) + i - 1) * WIN_X + columnid] = XPM_NO[pxl];
		file->rcast->oset = (int)((half - i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * NO_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * NO_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) - i) * WIN_X + columnid] = XPM_NO[pxl];
		i++;
	}
}

void	textures_so(t_file *file, float wall_height, int columnid)
{
	int pxl;
	int half;
	int i;

	file->rcast->oset = file->rcast->oset * 100 / TILE_SIZE;
	file->rcast->x_text = (int)((file->rcast->oset * SO_WIDTH) / 100);
	half = wall_height / 2;
	i = 0;
	while (i < half && i <= WIN_Y / 2)
	{
		file->rcast->oset = (int)((half + i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * SO_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * SO_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) + i - 1) * WIN_X + columnid] = XPM_SO[pxl];
		file->rcast->oset = (int)((half - i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * SO_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * SO_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) - i) * WIN_X + columnid] = XPM_SO[pxl];
		i++;
	}
}

void	textures_we(t_file *file, float wall_height, int columnid)
{
	int pxl;
	int half;
	int i;

	file->rcast->oset = file->rcast->oset * 100 / TILE_SIZE;
	file->rcast->x_text = (int)((file->rcast->oset * WE_WIDTH) / 100);
	half = wall_height / 2;
	i = 0;
	while (i < half && i <= WIN_Y / 2)
	{
		file->rcast->oset = (int)((half + i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * WE_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * WE_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) + i - 1) * WIN_X + columnid] = XPM_WE[pxl];
		file->rcast->oset = (int)((half - i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * WE_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * WE_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) - i) * WIN_X + columnid] = XPM_WE[pxl];
		i++;
	}
}

void	textures_ea(t_file *file, float wall_height, int columnid)
{
	int pxl;
	int half;
	int i;

	file->rcast->oset = file->rcast->oset * 100 / TILE_SIZE;
	file->rcast->x_text = (int)(file->rcast->oset * EA_WIDTH) / 100;
	half = wall_height / 2;
	i = 0;
	while (i < half && i <= WIN_Y / 2)
	{
		file->rcast->oset = (int)((half + i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * EA_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * EA_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) + i - 1) * WIN_X + columnid] = XPM_EA[pxl];
		file->rcast->oset = (int)((half - i) * 100 / wall_height);
		file->rcast->y_text = (int)(file->rcast->oset * EA_HEIGHT) / 100;
		pxl = (int)(file->rcast->y_text * EA_WIDTH + file->rcast->x_text);
		PXL_CLR[((WIN_Y / 2) - i) * WIN_X + columnid] = XPM_EA[pxl];
		i++;
	}
}

void	projection_walls(t_file *file, int columnid)
{
	PROJECTION3D_DIST = (WIN_X / 2) / TAN((FOV / 2));
	WALL_HEIGHT = (TILE_SIZE / file->rcast->ray_dist) * PROJECTION3D_DIST;
	if (file->rcast->h_or_v == -1 && file->rcast->ray_ud == -1)
		textures_no(file, WALL_HEIGHT, columnid);
	else if (file->rcast->h_or_v == -1 && file->rcast->ray_ud == 1)
		textures_so(file, WALL_HEIGHT, columnid);
	else if (file->rcast->h_or_v == 1 && file->rcast->ray_rl == -1)
		textures_we(file, WALL_HEIGHT, columnid);
	else if (file->rcast->h_or_v == 1 && file->rcast->ray_rl == 1)
		textures_ea(file, WALL_HEIGHT, columnid);
}
