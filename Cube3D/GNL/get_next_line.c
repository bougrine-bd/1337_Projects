/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:46:53 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/07 18:54:24 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char **str)
{
	char	*buff;
	int		rdret;

	if ((!(buff = malloc(BUFFER_SIZE + 1)) ||
				(rdret = read(fd, buff, BUFFER_SIZE)) < 0))
		return (-1);
	buff[rdret] = '\0';
	*str = ft_strjoin(*str, buff);
	while (!(ft_strchr(*str, '\n')) &&
			(rdret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rdret] = '\0';
		*str = ft_strjoin(*str, buff);
	}
	free(buff);
	return (rdret);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*tmp;
	int			rdret;

	if (fd < 0 || !line)
		return (-1);
	if ((rdret = ft_read(fd, &str)) < 0)
		return (-1);
	tmp = ft_strccpy(line, str, '\n');
	if (!ft_strchr(str, '\n'))
		rdret = 0;
	else
		rdret = 1;
	free(str);
	str = NULL;
	return (rdret);
}
