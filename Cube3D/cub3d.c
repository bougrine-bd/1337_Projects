/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:25:21 by abougrin          #+#    #+#             */
/*   Updated: 2020/12/07 12:26:28 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_xpm(t_file *file, int zero)
{
	XPM_NO = mlx_xpm_file_to_image(MLX_PTR, NO, &NO_WIDTH, &NO_HEIGHT);
	XPM_SO = mlx_xpm_file_to_image(MLX_PTR, SO, &SO_WIDTH, &SO_HEIGHT);
	XPM_WE = mlx_xpm_file_to_image(MLX_PTR, WE, &WE_WIDTH, &WE_HEIGHT);
	XPM_EA = mlx_xpm_file_to_image(MLX_PTR, EA, &EA_WIDTH, &EA_HEIGHT);
	XPM_SP = mlx_xpm_file_to_image(MLX_PTR, SP, &SP_WIDTH, &SP_HEIGHT);
	if (!XPM_NO || !XPM_SO || !XPM_WE || !XPM_EA || !XPM_SP)
	{
		write(1, "Error\n-Invalid path!\n", 21);
		last_exit(file);
	}
	XPM_NO = (int *)mlx_get_data_addr(XPM_NO, &zero, &zero, &zero);
	XPM_SO = (int *)mlx_get_data_addr(XPM_SO, &zero, &zero, &zero);
	XPM_WE = (int *)mlx_get_data_addr(XPM_WE, &zero, &zero, &zero);
	XPM_EA = (int *)mlx_get_data_addr(XPM_EA, &zero, &zero, &zero);
	XPM_SP = (int *)mlx_get_data_addr(XPM_SP, &zero, &zero, &zero);
}

void	cub3d(t_file *file, int fd)
{
	int		zero;
	char	*line;

	line = NULL;
	file->element_nb = 0;
	file->nb_line = 0;
	check_file(fd, file, line);
	if (file->nb_line == 0)
	{
		write(1, "Error\n-Invalid File!\n", 21);
		exit_(file, line, 0);
	}
	initialize(file);
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "Cub3D");
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	PXL_CLR = (int *)mlx_get_data_addr(IMG_PTR, &zero, &zero, &zero);
	all_xpm(file, zero);
	draw_fc(*file, 0, 0);
	castrays(file);
	mlx_hook(WIN_PTR, 2, 0, player_move, file);
	mlx_hook(WIN_PTR, 17, 0, last_exit, file);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	mlx_loop(MLX_PTR);
}

int		check_name(char *name, int index)
{
	int cub;
	int save;

	if (index == 1)
	{
		cub = ft_strlen(name) - 4;
		if (name[cub] != '.' || name[cub + 1] != 'c'
			|| name[cub + 2] != 'u' || name[cub + 3] != 'b')
			return (-1);
	}
	else
	{
		save = ft_strlen(name);
		if (name[save - 6] != '-' || name[save - 5] != '-'
			|| name[save - 4] != 's' || name[save - 3] != 'a'
			|| name[save - 2] != 'v' || name[save - 1] != 'e' || save > 6)
			return (-1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_file	*file;

	file = malloc(sizeof(t_file));
	file->player = malloc(sizeof(t_player));
	file->rcast = malloc(sizeof(t_raycast));
	file->save = malloc(sizeof(t_save));
	give_it_null(file);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || check_name(argv[1], 1) == -1)
	{
		write(1, "Error\n-Invalid File Name!\n", 26);
		first_exit(file);
	}
	else if ((argv[2] && check_name(argv[2], 2 == -1)) || argc > 3)
	{
		write(1, "Error\n-Invalid input!\n", 22);
		first_exit(file);
	}
	else if (argv[2] && check_name(argv[2], 2) == 0)
		create_img(file, fd);
	cub3d(file, fd);
	close(fd);
	return (0);
}
