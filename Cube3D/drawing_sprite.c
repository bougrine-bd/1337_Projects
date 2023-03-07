/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:26:19 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/25 09:10:40 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_vsprite(float *x, float *y)
{
	float	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	sort_sprite(t_file *file, int length)
{
	t_slist	*temp;

	temp = file->slist;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	while (length--)
	{
		temp = file->slist;
		while (temp->next)
		{
			if (temp->radius < temp->next->radius)
			{
				swap_vsprite(&temp->next->radius, &temp->radius);
				swap_vsprite(&temp->next->center_p_to_sprite_p,
							&temp->center_p_to_sprite_p);
				swap_vsprite(&temp->next->sprite_x, &temp->sprite_x);
				swap_vsprite(&temp->next->sprite_y, &temp->sprite_y);
				swap_vsprite(&temp->next->sprite_height, &temp->sprite_height);
			}
			temp = temp->next;
		}
	}
}

void	projection_sprite(t_file *file, int columnid, int i)
{
	int	p_width;
	int	p_height;
	int	pxl;

	p_width = C_S_DIST * 100 / TILE_SIZE * SP_WIDTH / 100;
	if (C_S_DIST >= 64 || C_S_DIST < 0)
		return ;
	while (i < SPRITE_HEIGHT / 2 && i < WIN_Y / 2)
	{
		p_height = (SPRITE_HEIGHT / 2 + i) * 100 / SPRITE_HEIGHT;
		p_height = (int)(p_height * SP_HEIGHT / 100);
		pxl = (int)(p_height * SP_WIDTH + p_width);
		if (XPM_SP[pxl])
			PXL_CLR[(WIN_Y / 2 + i) * WIN_X + columnid] = XPM_SP[pxl];
		p_height = (SPRITE_HEIGHT / 2 - i) * 100 / SPRITE_HEIGHT;
		p_height = (int)(p_height * SP_HEIGHT / 100);
		pxl = (int)(p_height * SP_WIDTH + p_width);
		if (XPM_SP[pxl])
			PXL_CLR[(WIN_Y / 2 - i) * WIN_X + columnid] = XPM_SP[pxl];
		i++;
	}
}

void	sprite_inter(t_file *file, float center_x, float center_y)
{
	float	s_angle;
	float	ray_angle;
	float	x;
	t_slist	*element;
	t_slist	*temp;

	element = malloc(sizeof(t_slist));
	RADIUS = DISTANCE(PLAYER_X, center_x, PLAYER_Y, center_y);
	SPRITE_X2 = COS(RAY_ANGLE) * RADIUS + PLAYER_X;
	SPRITE_Y2 = SIN(RAY_ANGLE) * RADIUS + PLAYER_Y;
	SPRITE_HEIGHT2 = (TILE_SIZE / RADIUS) * PROJECTION3D_DIST;
	s_angle = center_y >= PLAYER_Y ? acos((center_x - PLAYER_X) / RADIUS) *
			180 / M_PI : -(acos((center_x - PLAYER_X) / RADIUS) * 180 / M_PI);
	x = 180 - s_angle;
	ray_angle = zero_360(RAY_ANGLE + x);
	if (ray_angle < 180)
		C_S_DIST2 = -DISTANCE(SPRITE_X2, center_x, SPRITE_Y2, center_y) + 32;
	else
		C_S_DIST2 = DISTANCE(SPRITE_X2, center_x, SPRITE_Y2, center_y) + 32;
	temp = file->slist;
	file->slist = element;
	file->slist->next = temp;
}
