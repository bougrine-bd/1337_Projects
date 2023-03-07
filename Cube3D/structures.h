/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:05:00 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/24 09:52:13 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct			s_saveimage
{
	int					width;
	int					height;
	int					bitcount;
	int					width_in_bytes;
	int					imagesize;
	int					bisize;
	int					bfoffbits;
	int					filesize;
	int					biplanes;
}						t_save;

typedef	struct			s_spritelist
{
	float				radius;
	float				center_p_to_sprite_p;
	float				sprite_x;
	float				sprite_y;
	float				sprite_height;
	struct s_spritelist	*next;
}						t_slist;

typedef struct			s_player
{
	char				direction;
	float				x;
	float				y;
	float				angle;
}						t_player;

typedef	struct			s_raycast
{
	float				ray_dist;
	float				sray_dist;
	float				ray_angle;
	int					ray_ud;
	int					ray_rl;
	int					oset;
	int					x_text;
	int					y_text;
	int					h_or_v;
}						t_raycast;

typedef struct			s_inter
{
	float				h_yinter;
	float				h_xinter;
	float				h_distance;
	float				v_yinter;
	float				v_xinter;
	float				v_distance;
	float				ystep;
	float				xstep;
}						t_inter;

typedef struct			s_file
{
	t_player			*player;
	t_raycast			*rcast;
	t_inter				*inter;
	t_slist				*slist;
	t_slist				*start_slist;
	t_save				*save;

	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*pxl_clr;
	int					*xpm_no;
	int					*xpm_so;
	int					*xpm_we;
	int					*xpm_ea;
	int					*xpm_sp;

	int					win_x;
	int					win_y;
	char				*north;
	int					no_height;
	int					no_width;
	char				*south;
	int					so_height;
	int					so_width;
	char				*west;
	int					we_height;
	int					we_width;
	char				*east;
	int					ea_height;
	int					ea_width;
	char				*sprite;
	int					sp_height;
	int					sp_width;
	int					floor;
	int					ceilling;
	int					element_nb;

	int					**map;
	int					columns;
	int					rows;

	float				dis_3dprojection;
	float				wall_height;

	char				*str_add;

	int					nb_line;
}						t_file;

#endif
