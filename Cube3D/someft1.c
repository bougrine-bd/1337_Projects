/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someft1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:29:39 by abougrin          #+#    #+#             */
/*   Updated: 2020/11/19 13:58:02 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	c_strlen(char *str, int c)
{
	int ret;

	ret = 0;
	if (!str)
		return (0);
	while (*str != c)
	{
		str++;
		ret++;
	}
	return (ret);
}

char	*z_space(char *src, char *dest, int i)
{
	int		res;

	res = ft_strlen(src);
	dest = malloc(res + 1);
	while (*src)
	{
		while (*src == ' ')
		{
			dest[i] = '8';
			src++;
			i++;
		}
		if (!*src)
			break ;
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

int		c_atoi(int c)
{
	int	cc;

	cc = 0;
	if (c <= '9' && c >= '0')
		cc = c - '0';
	return (cc);
}

float	zero_360(float angle)
{
	angle = fmod(angle, 360);
	if (angle < 0)
		angle += 360;
	return (angle);
}
