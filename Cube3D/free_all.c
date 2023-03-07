/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:37:00 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/18 12:56:12 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	give_it_null(t_file *file)
{
	file->north = NULL;
	file->south = NULL;
	file->east = NULL;
	file->west = NULL;
	file->sprite = NULL;
	file->start_slist = NULL;
	file->map = NULL;
}

void	first_exit(t_file *file)
{
	free(file->rcast);
	free(file->player);
	free(file);
	exit(0);
}

int		exit_(t_file *file, char *line, int i)
{
	if (line)
		free(line);
	if (file->map)
	{
		while (i < file->rows)
		{
			free(file->map[i]);
			i++;
		}
		free(file->map);
	}
	if (file->north)
		free(file->north);
	if (file->west)
		free(file->west);
	if (file->south)
		free(file->south);
	if (file->east)
		free(file->east);
	if (file->sprite)
		free(file->sprite);
	free(file->rcast);
	free(file->player);
	free(file);
	exit(0);
}

void	free_sprite(t_file *file)
{
	t_slist	*temp;

	if (file->start_slist)
	{
		while (file->start_slist->next)
		{
			temp = file->start_slist->next;
			free(file->start_slist);
			file->start_slist = temp;
		}
		free(file->start_slist);
	}
	file->start_slist = NULL;
}

int		last_exit(t_file *file)
{
	int i;

	i = 0;
	while (i < file->rows)
	{
		free(file->map[i]);
		i++;
	}
	free(file->map);
	free_sprite(file);
	free(file->north);
	free(file->west);
	free(file->south);
	free(file->east);
	free(file->sprite);
	free(file->rcast);
	free(file->player);
	free(file);
	exit(0);
}
