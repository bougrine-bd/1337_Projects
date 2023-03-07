/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:19:37 by abougrin          #+#    #+#             */
/*   Updated: 2021/10/19 17:24:08 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	count_commands(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '"'))
			i = skip_quotes(str, i);
		else if (str[i] && str[i] == c)
		{
			count++;
			i++;
		}
		else
			i++;
	}
	count++;
	return (count);
}

void	split_cmd(char *command, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	g_data.num_cmd = count_commands(command, c);
	g_data.cmds = malloc(g_data.num_cmd * sizeof(t_cmds));
	while (command[i] && command[i] == ' ')
		i++;
	if (!command[i])
		g_data.cmds[j].cmd = NULL;
	while (command[i])
	{
		g_data.cmds[j].cmd = &command[i];
		i = skip_to_token(command, i);
		if (command[i] && command[i] == c)
		{
			g_data.cmds[j++].tok = c;
			command[i++] = '\0';
		}
	}
	g_data.cmds[j].tok = '\0';
}
