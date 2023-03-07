/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:30:17 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/20 07:25:11 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	if (!str || !str[length])
		return (0);
	while (str[++length])
		NULL;
	return (length);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!(*s1) && !(*s2))
		return (0);
	return (*s1 - *s2);
}

int	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (i);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

int	ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str)
		return (1);
	return (0);
}

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i += 1;
	return (i);
}
