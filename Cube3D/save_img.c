/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:26:36 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/25 10:52:38 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	givecolor(t_file *file, unsigned char *header)
{
	unsigned char	*buf;
	int				row;
	int				col;
	int				pxl_clr;
	FILE			*fout;

	buf = malloc(IMAGESIZE);
	row = -1;
	while (++row < HEIGHT)
	{
		col = -1;
		while (++col < WIDTH)
		{
			pxl_clr = PXL_CLR[(HEIGHT - row) * WIDTH + col];
			buf[(row * WIDTH + col) * 3 + 0] = pxl_clr % 256;
			buf[(row * WIDTH + col) * 3 + 1] = pxl_clr % 65536 / 256;
			buf[(row * WIDTH + col) * 3 + 2] = pxl_clr / 65536;
		}
	}
	fout = fopen("Screen Shot.bmp", "w+");
	fwrite(header, 1, 54, fout);
	fwrite((char*)buf, 1, IMAGESIZE, fout);
	fclose(fout);
	free(buf);
	first_exit(file);
}

void	copytoheader(t_file *file)
{
	unsigned char	header[54];
	int				i;

	i = 0;
	while (i < 54)
	{
		header[i] = 0;
		i++;
	}
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &FILESIZE, 4);
	ft_memcpy(header + 10, &BFOFFBITS, 4);
	ft_memcpy(header + 14, &BISIZE, 4);
	ft_memcpy(header + 18, &WIDTH, 4);
	ft_memcpy(header + 22, &HEIGHT, 4);
	ft_memcpy(header + 26, &BIPLANES, 2);
	ft_memcpy(header + 28, &BITCOUNT, 2);
	ft_memcpy(header + 34, &IMAGESIZE, 4);
	givecolor(file, header);
}

void	save_img(t_file *file)
{
	WIDTH = WIN_X;
	HEIGHT = WIN_Y;
	BITCOUNT = 24;
	WIDTH_IN_BYTES = ((WIDTH * BITCOUNT + 31) / 32) * 4;
	IMAGESIZE = WIDTH_IN_BYTES * HEIGHT;
	BISIZE = 40;
	BFOFFBITS = 54;
	FILESIZE = 54 + IMAGESIZE;
	BIPLANES = 1;
	copytoheader(file);
}

void	create_img(t_file *file, int fd)
{
	int		zero;
	char	*line;

	line = NULL;
	file->element_nb = 0;
	file->nb_line = 0;
	check_file(fd, file, line);
	if (file->nb_line == 0)
	{
		write(1, "Error\n-Invalid File1\n", 21);
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
	save_img(file);
}
