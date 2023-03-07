/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:12:16 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/27 18:25:43 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countw(char const *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	count++;
	return (count);
}

int		ft_len(char const *str, char c)
{
	int cp;

	cp = 0;
	while (str[cp] && str[cp] != c)
		cp++;
	return (cp);
}

char	*ft_cpy(char *dest, char const *src, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] == c)
		i++;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_free_split(char ***p, int i)
{
	while (i >= 0)
	{
		free(p[0][i]);
		i--;
	}
	free(*p);
	*p = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s2d;
	int		i;

	if (!s)
		return (NULL);
	s2d = malloc((ft_countw(s, c) + 1) * sizeof(char *));
	if (s2d == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!(*s))
			break ;
		s2d[i] = malloc(ft_len(s, c) * sizeof(char) + 1);
		if (!s2d[i])
			return (ft_free_split(&s2d, i - 1));
		s2d[i] = ft_cpy(s2d[i], s, c);
		s += ft_len(s, c);
		i++;
	}
	s2d[i] = 0;
	return (s2d);
}
