/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:27:34 by abougrin          #+#    #+#             */
/*   Updated: 2019/11/18 09:17:18 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!(res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		res[i] = *(s2++);
		i++;
	}
	if (s1)
		free(s1);
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *str, int c)
{
	while (*str && str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strccpy(char **s1, char *s2, int c)
{
	char	*res;
	int		i;

	i = 0;
	while (s2 && s2[i] && s2[i] != c)
		i++;
	if (!(res = malloc(i * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (s2 && *s2 && *s2 != c)
		res[i++] = *(s2++);
	res[i] = '\0';
	*s1 = res;
	if (s2 && *s2 && *s2 == c)
		return (++s2);
	return (NULL);
}
