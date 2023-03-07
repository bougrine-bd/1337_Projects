/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:20:44 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/24 09:33:18 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "cub3d.h"

# define MAX_WIDTH 2560
# define MAX_HIGHT 1440
# define TILE_SIZE 64
# define FOV 60

# define PLAYER_X file->player->x
# define PLAYER_Y file->player->y
# define PLAYER_ANGLE file->player->angle

# define COS(X) cos(X * M_PI / 180)
# define SIN(X) sin(X * M_PI / 180)
# define TAN(X) tan(X * M_PI / 180)
/*
** MLX's
*/
# define MLX_PTR file->mlx_ptr
# define WIN_PTR file->win_ptr
# define IMG_PTR file->img_ptr
# define PXL_CLR file->pxl_clr
/*
** XPM's
*/
# define XPM_NO file->xpm_no
# define XPM_SO file->xpm_so
# define XPM_WE file->xpm_we
# define XPM_EA file->xpm_ea
# define XPM_SP file->xpm_sp

# define NO_WIDTH file->no_width
# define NO_HEIGHT file->no_height
# define SO_WIDTH file->so_width
# define SO_HEIGHT file->so_height
# define WE_WIDTH file->we_width
# define WE_HEIGHT file->we_height
# define EA_WIDTH file->ea_width
# define EA_HEIGHT file->ea_height
# define SP_WIDTH file->sp_width
# define SP_HEIGHT file->sp_height
/*
** used in check_file.c
*/
# define WIN_X file->win_x
# define WIN_Y file->win_y
# define NO file->north
# define SO file->south
# define WE file->west
# define EA file->east
# define SP file->sprite
# define F file->floor
# define C file->ceilling
/*
** map
*/
# define MAP file.map
/*
** .c
*/
# define RAY_ANGLE file->rcast->ray_angle
# define RAY_UD file->rcast->ray_ud
# define RAY_RL file->rcast->ray_rl
/*
** used in drawing walls
*/
# define PROJECTION3D_DIST file->dis_3dprojection
# define WALL_HEIGHT file->wall_height
/*
** drawing sprite
*/
# define SPRITE_X file->slist->sprite_x
# define SPRITE_Y file->slist->sprite_y
# define C_S_DIST file->slist->center_p_to_sprite_p
# define SPRITE_HEIGHT file->slist->sprite_height

# define RADIUS element->radius
# define SPRITE_X2 element->sprite_x
# define SPRITE_Y2 element->sprite_y
# define C_S_DIST2 element->center_p_to_sprite_p
# define SPRITE_HEIGHT2 element->sprite_height

# define DISTANCE(X, X1, Y, Y1) sqrt(pow((X - X1), 2) + pow((Y - Y1), 2))
/*
** save image
*/
# define WIDTH file->save->width
# define HEIGHT file->save->height
# define BITCOUNT file->save->bitcount
# define WIDTH_IN_BYTES file->save->width_in_bytes
# define IMAGESIZE file->save->imagesize
# define BISIZE file->save->bisize
# define BFOFFBITS file->save->bfoffbits
# define FILESIZE file->save->filesize
# define BIPLANES file->save->biplanes

#endif
