/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:19:53 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/19 17:17:53 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	inside_quotes_length(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '"')
	{
		while (str[++i] != '"')
		{
			if (str[i] == '$' && isvar(str[i + 1]))
			{
				len += ft_strlen(
						search_variable_value(g_data.envp, &str[i + 1]));
				i += variable_name_length(&str[i + 1]);
			}
			else
				len++;
		}
		return (len);
	}
	while (str[++i] != '\'')
		len++;
	return (len);
}

int	copy_inside_quotes(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src[j] == '"')
	{
		while (src[++j] != '"')
		{
			if (src[j] == '$' && isvar(src[j + 1]))
			{
				i += ft_strcpy(&dst[i],
						search_variable_value(g_data.envp, &src[j + 1]));
				j += variable_name_length(&src[j + 1]);
			}
			else
				dst[i++] = src[j];
		}
		return (i);
	}
	while (src[++j] != '\'')
		dst[i++] = src[j];
	return (i);
}

int	quotes_skip(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '"')
	{
		while (str[++i] != '"')
			;
	}
	if (str[i] == '\'')
		while (str[++i] != '\'')
			;
	return (++i);
}
