/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:18:21 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/22 23:24:03 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_set(char *str, const char *set)
{
	int i;

	while (*str)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == *str)
				break ;
			i++;
		}
		if (set[i] != *str)
			break ;
		str++;
	}
	return (str);
}

int		ft_setend(char *str, const char *set, int i)
{
	int j;
	int indx;

	indx = 0;
	while (i--)
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == str[i])
				break ;
			j++;
		}
		if (set[j] != str[i])
			break ;
		indx++;
	}
	return (indx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cs1;
	char	*s2;
	int		i;
	int		indx;

	if (!s1)
		return (NULL);
	cs1 = (char *)s1;
	cs1 = ft_set(cs1, set);
	indx = ft_strlen(cs1) - (ft_setend(cs1, set, ft_strlen(cs1)));
	s2 = malloc(indx * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (indx--)
	{
		s2[i] = cs1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
