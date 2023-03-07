/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:09:16 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/03 10:06:37 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

char	*extract_delim(char *cmd, int *exp_vars)
{
	int		i;
	char	quote_type;
	char	*delim;

	i = 0;
	cmd += skip_spaces(cmd);
	delim = malloc(delim_length(cmd) + 1);
	if (!delim)
		return (NULL);
	while (*cmd && *cmd != ' ')
	{
		if (*cmd == '"' || *cmd == '\'')
		{
			*exp_vars = 0;
			quote_type = *cmd;
			while (*(++cmd) != quote_type)
				delim[i++] = *cmd;
		}
		else
			delim[i++] = *cmd;
		cmd++;
	}
	delim[i] = '\0';
	return (delim);
}

int	delim_length(char *cmd)
{
	int		length;
	char	quote_type;

	length = 0;
	while (*cmd)
	{
		if (*cmd == '"' || *cmd == '\'')
		{
			quote_type = *cmd;
			while (*(++cmd) != quote_type)
				length++;
			cmd++;
		}
		else
		{
			length++;
			cmd++;
		}
	}
	return (length);
}

int	heredoc_readlines(int fd, char *delim, int exp_vars)
{
	char	*line;
	char	*temp;	

	line = NULL;
	while (1 && !g_data.stopped)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(delim, line))
			break ;
		if (exp_vars)
		{
			temp = line;
			line = heredoc_parse_line(line);
			free(temp);
			if (!line)
				return (1);
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	return (0);
}

char	*heredoc_parse_line(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(heredoc_line_length(str) + 1);
	while (str[j])
	{
		if (str[j] == '$' && isvar(str[j + 1]))
		{
			i += ft_strcpy(&new_str[i],
					search_variable_value(g_data.envp, &str[j + 1]));
			j += variable_name_length(&str[j + 1]) + 1;
		}
		else
		{
			new_str[i] = str[j];
			i++;
			j++;
		}
	}
	new_str[i] = '\0';
	return (new_str);
}

int	heredoc_line_length(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$' && isvar(str[i + 1]))
		{
			len += ft_strlen(search_variable_value(g_data.envp, &str[i + 1]));
			i += variable_name_length(&str[i + 1]) + 1;
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}
