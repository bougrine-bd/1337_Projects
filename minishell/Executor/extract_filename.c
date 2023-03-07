/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 08:09:51 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/19 17:17:53 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

char	*extract_filename(char *str)
{
	int		i;
	int		len;
	char	*filename;

	i = 0;
	str += skip_spaces(str);
	len = filename_length(str);
	if (len == 0 && *str == '$')
	{
		puterr("ambiguous redirect", 1);
		return (NULL);
	}
	filename = malloc(len + 1);
	if (!filename)
	{
		puterr(strerror(errno), 1);
		return (NULL);
	}
	filename = fill_filename(filename, str);
	return (filename);
}

int	filename_length(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != ' ' && str[i] != '<' && str[i] != '>')
	{
		if (str[i] == '$' && isvar(str[i + 1]))
		{
			len += ft_strlen(search_variable_value(g_data.envp, &str[i + 1]));
			i += variable_name_length(&str[i + 1]) + 1;
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
			len += inside_quotes_length(&str[i]);
			i += quotes_skip(&str[i]);
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*fill_filename(char *filename, char *str)
{
	int	i;

	i = 0;
	while (*str && *str != ' ' && *str != '<' && *str != '>')
	{
		if (*str == '$' && isvar(*(str + 1)))
		{
			i += ft_strcpy(&filename[i],
					search_variable_value(g_data.envp, str + 1));
			str += variable_name_length(str + 1) + 1;
		}
		else if (*str == '"' || *str == '\'')
		{
			i += copy_inside_quotes(&filename[i], str);
			str += quotes_skip(str);
		}
		else
			filename[i++] = *(str++);
	}
	filename[i] = '\0';
	return (filename);
}
