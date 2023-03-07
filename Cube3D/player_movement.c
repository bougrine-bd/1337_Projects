/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:23:56 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/22 09:29:21 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		iswall(t_file *file, int newx, int newy, int i)
{
	if (newx < 0 || newy < 0 || newy >= file->rows || newx >= file->columns)
		return (1);
	if (i == 0)
	{
		if (file->map[newy][newx] == 1 || file->map[newy][newx] == 2)
			return (1);
	}
	else if (i == 1)
	{
		if (file->map[newy][newx] == 1)
			return (1);
		if (file->map[newy][newx] == 2)
			sprite_inter(file, newx * TILE_SIZE + 32, newy * TILE_SIZE + 32);
	}
	return (0);
}

void	up_or_down(t_file *file, int key, int newx, int newy)
{
	if (key == 1)
	{
		newx = floor((PLAYER_X - COS(PLAYER_ANGLE) * 35) / TILE_SIZE);
		newy = floor((PLAYER_Y - SIN(PLAYER_ANGLE) * 35) / TILE_SIZE);
		if (iswall(file, newx, newy, 0) == 0)
		{
			PLAYER_Y -= SIN(PLAYER_ANGLE) * 30;
			PLAYER_X -= COS(PLAYER_ANGLE) * 30;
		}
	}
	else if (key == 13)
	{
		newx = floor((PLAYER_X + COS(PLAYER_ANGLE) * 35) / TILE_SIZE);
		newy = floor((PLAYER_Y + SIN(PLAYER_ANGLE) * 35) / TILE_SIZE);
		if (iswall(file, newx, newy, 0) == 0)
		{
			PLAYER_Y += SIN(PLAYER_ANGLE) * 30;
			PLAYER_X += COS(PLAYER_ANGLE) * 30;
		}
	}
}

void	right_or_left(t_file *file, int key, int newx, int newy)
{
	if (key == 0)
	{
		newx = floor((PLAYER_X + COS((PLAYER_ANGLE - 90)) * 35) / TILE_SIZE);
		newy = floor((PLAYER_Y + SIN((PLAYER_ANGLE - 90)) * 35) / TILE_SIZE);
		if (iswall(file, newx, newy, 0) == 0)
		{
			PLAYER_Y += SIN((PLAYER_ANGLE - 90)) * 30;
			PLAYER_X += COS((PLAYER_ANGLE - 90)) * 30;
		}
	}
	else if (key == 2)
	{
		newx = floor((PLAYER_X + COS((PLAYER_ANGLE + 90)) * 35) / TILE_SIZE);
		newy = floor((PLAYER_Y + SIN((PLAYER_ANGLE + 90)) * 35) / TILE_SIZE);
		if (iswall(file, newx, newy, 0) == 0)
		{
			PLAYER_Y += SIN((PLAYER_ANGLE + 90)) * 30;
			PLAYER_X += COS((PLAYER_ANGLE + 90)) * 30;
		}
	}
	up_or_down(file, key, 0, 0);
}

int		player_move(int key, t_file *file)
{
	draw_fc(*file, 0, 0);
	if (key == 53)
		last_exit(file);
	else if (key == 124)
	{
		PLAYER_ANGLE += 5;
	}
	else if (key == 123)
	{
		PLAYER_ANGLE -= 5;
	}
	else
		right_or_left(file, key, 0, 0);
	castrays(file);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	return (0);
}
