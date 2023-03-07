/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:39:55 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/02 09:26:15 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

char	*ft_strdup(char *str)
{
	int		length;
	char	*new_str;

	length = ft_strlen(str);
	new_str = malloc((length + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, str);
	return (new_str);
}

char	*ft_substr(char *str, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((end - start) + 1);
	if (!dest)
		return (NULL);
	while (start < end)
		dest[i++] = str[start++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s1 && *s1)
		dest[i++] = *(s1++);
	while (s2 && *s2)
		dest[i++] = *(s2++);
	dest[i] = '\0';
	return (dest);
}

char	*join_3string(char *s1, char *s2, char *s3)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (!dest)
		return (NULL);
	while (*s1)
		dest[i++] = *(s1++);
	while (*s2)
		dest[i++] = *(s2++);
	while (*s3)
		dest[i++] = *(s3++);
	dest[i] = '\0';
	return (dest);
}

void	puterr(char *err, int exit_stat)
{
	write(2, "ERROR : ", 8);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	g_data.exit_stat = exit_stat;
	errno = 0;
}
