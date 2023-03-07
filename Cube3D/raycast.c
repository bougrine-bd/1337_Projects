/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:43:12 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/24 11:06:39 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_facing(t_file *file)
{
	float rayangle;

	file->rcast->ray_angle = zero_360(file->rcast->ray_angle);
	rayangle = file->rcast->ray_angle;
	if (rayangle > 0 && rayangle < 180)
		file->rcast->ray_ud = 1;
	else if (!(rayangle > 0 && rayangle < 180))
		file->rcast->ray_ud = -1;
	if (rayangle > 90 && rayangle < 270)
		file->rcast->ray_rl = -1;
	else if (!(rayangle > 90 && rayangle < 270))
		file->rcast->ray_rl = 1;
}

void	h_inter(t_file *file, t_inter *inter, int con)
{
	ray_facing(file);
	inter->h_yinter = floor(PLAYER_Y / TILE_SIZE) * TILE_SIZE;
	inter->h_yinter += file->rcast->ray_ud == 1 ? TILE_SIZE : -1;
	con = file->rcast->ray_ud == 1 ? 0 : 1;
	inter->h_xinter = PLAYER_X +
		(inter->h_yinter + con - PLAYER_Y) / TAN(RAY_ANGLE);
	inter->ystep = TILE_SIZE * file->rcast->ray_ud;
	inter->xstep = inter->ystep / TAN(RAY_ANGLE);
	while (1)
	{
		if (iswall(file, floor(inter->h_xinter / TILE_SIZE),
			floor(inter->h_yinter / TILE_SIZE), 1) == 1)
		{
			inter->h_yinter += con;
			inter->h_distance = fabs((PLAYER_Y - inter->h_yinter) /
			SIN(RAY_ANGLE));
			break ;
		}
		inter->h_yinter += inter->ystep;
		inter->h_xinter += inter->xstep;
	}
}

void	v_inter(t_file *file, t_inter *inter, int con)
{
	ray_facing(file);
	inter->v_xinter = floor(PLAYER_X / TILE_SIZE) * TILE_SIZE;
	inter->v_xinter += file->rcast->ray_rl == 1 ? TILE_SIZE : -1;
	con = file->rcast->ray_rl == 1 ? 0 : 1;
	inter->v_yinter = PLAYER_Y +
		(inter->v_xinter + con - PLAYER_X) * TAN(RAY_ANGLE);
	inter->xstep = TILE_SIZE * file->rcast->ray_rl;
	inter->ystep = inter->xstep * TAN(RAY_ANGLE);
	while (1)
	{
		if (iswall(file, floor(inter->v_xinter / TILE_SIZE),
			floor(inter->v_yinter / TILE_SIZE), 1) == 1)
		{
			inter->v_xinter += con;
			inter->v_distance = fabs((PLAYER_X - inter->v_xinter) /
				COS(RAY_ANGLE));
			break ;
		}
		inter->v_yinter += inter->ystep;
		inter->v_xinter += inter->xstep;
	}
}

void	check_inter(t_file *file)
{
	t_inter *inter;

	inter = malloc(sizeof(t_inter));
	h_inter(file, inter, 0);
	v_inter(file, inter, 0);
	if (inter->h_distance < inter->v_distance)
	{
		file->rcast->sray_dist = inter->h_distance;
		file->rcast->ray_dist = inter->h_distance *
			COS((RAY_ANGLE - file->player->angle));
		file->rcast->oset = fmod(inter->h_xinter, TILE_SIZE);
		file->rcast->h_or_v = -1;
	}
	else
	{
		file->rcast->sray_dist = inter->v_distance;
		file->rcast->ray_dist = inter->v_distance *
			COS((RAY_ANGLE - file->player->angle));
		file->rcast->oset = fmod(inter->v_yinter, TILE_SIZE);
		file->rcast->h_or_v = 1;
	}
	free(inter);
}

void	castrays(t_file *file)
{
	float	raynb;
	int		columnid;

	raynb = WIN_X;
	RAY_ANGLE = PLAYER_ANGLE - (FOV / 2);
	columnid = 0;
	while (columnid < raynb)
	{
		file->slist = NULL;
		check_inter(file);
		projection_walls(file, columnid);
		sort_sprite(file, 0);
		file->start_slist = file->slist;
		while (file->slist)
		{
			if (file->rcast->sray_dist > file->slist->radius)
				projection_sprite(file, columnid, 0);
			file->slist = file->slist->next;
		}
		free_sprite(file);
		RAY_ANGLE += FOV / raynb;
		columnid++;
	}
}
