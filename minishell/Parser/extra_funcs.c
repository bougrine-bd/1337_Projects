/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:35:15 by abougrin          #+#    #+#             */
/*   Updated: 2021/10/27 12:38:37 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_chars(char command)
{
	if (((command >= '0' && command <= '9')
			|| (command >= 'A' && command <= 'Z')
			|| (command >= '_' && command <= 'z'))
		&& command != '`')
		return (1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (-1);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		else
			i++;
	}
	return (0);
}

int	skip_quotes(char *str, int k)
{
	if (str[k] && (str[k] == '\'' || str[k] == '"'))
	{
		if (str[k] && str[k] == '\'')
			while (str[k] && str[++k] != '\'')
				;
		else if (str[k] && str[k] == '"')
			while (str[k] && str[++k] != '"')
				;
		else
			k++;
	}
	return (++k);
}

int	skip_to_token(char *str, int i)
{
	while (str[i] && str[i] != '|')
	{
		if (str[i] && (str[i] == '\'' || str[i] == '"'))
			i = skip_quotes(str, i);
		else
			i++;
	}
	return (i);
}

int	skip_red(char *str, int i)
{
	if (str[i] && (str[i] == '>' || str[i] == '<'))
	{
		i++;
		if (str[i] && (str[i] == '>' || str[i] == '<'))
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
		{
			if (str[i] == '\'' || str[i] == '"')
				i = skip_quotes(str, i);
			else
				i++;
		}
	}
	return (i);
}
