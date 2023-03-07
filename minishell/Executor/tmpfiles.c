/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmpfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:55:41 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/02 11:38:08 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

char	*create_new_tmpfile(void)
{
	int		id;
	char	*str_id;
	char	*tmpfile;

	id = tmpfiles_size();
	str_id = ft_itoa(id);
	if (!str_id)
		return (NULL);
	tmpfile = ft_strjoin("/tmp/file", str_id);
	if (!tmpfile || add_tmpfile(tmpfile))
	{
		free(str_id);
		free(tmpfile);
		return (NULL);
	}
	free(str_id);
	return (tmpfile);
}

int	tmpfiles_size(void)
{
	int			size;
	t_tmpfiles	*tmpfiles;

	size = 0;
	tmpfiles = g_data.tmpfiles;
	while (tmpfiles)
	{
		size++;
		tmpfiles = tmpfiles->next;
	}
	return (size);
}

int	add_tmpfile(char *tmpfile)
{
	t_tmpfiles	*element;
	t_tmpfiles	*tmpfiles;

	tmpfiles = g_data.tmpfiles;
	element = malloc(sizeof(t_tmpfiles));
	if (!element)
		return (1);
	element->path = tmpfile;
	element->next = NULL;
	if (!g_data.tmpfiles)
		g_data.tmpfiles = element;
	else
	{
		while (tmpfiles->next)
			tmpfiles = tmpfiles->next;
		tmpfiles->next = element;
	}
	return (0);
}

void	clear_tmpfiles(void)
{
	t_tmpfiles	*next;

	while (g_data.tmpfiles)
	{
		next = g_data.tmpfiles->next;
		unlink(g_data.tmpfiles->path);
		free(g_data.tmpfiles->path);
		free(g_data.tmpfiles);
		g_data.tmpfiles = next;
	}
}
