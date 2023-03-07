/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:14:33 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/06 11:52:40 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	len_of_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '\'' || str[i] == '"')
			i = skip_quotes(str, i);
		else if ((str[i] == '>' || str[i] == '<'))
			break ;
		else
			i++;
	}
	return (i);
}

void	copy_in_quotes(char *temp, char *str, int j, int *i)
{
	while (str[*i] && str[*i] != ' ' && str[*i] != '<' && str[*i] != '>')
	{
		if (str[*i] && str[*i] == '\'')
		{
			(*i)++;
			while (str[*i] && str[*i] != '\'')
				temp[j++] = str[(*i)++];
			(*i)++;
		}
		else if (str[*i] && str[*i] == '"')
		{
			(*i)++;
			while (str[*i] && str[*i] != '"')
				temp[j++] = str[(*i)++];
			(*i)++;
		}
		else
			temp[j++] = str[(*i)++];
	}
	temp[j] = '\0';
}

char	*copy_args(char *str, int *i)
{
	int		j;
	char	*temp;

	temp = malloc(len_of_arg(&str[*i]) + 1);
	j = 0;
	while (str[*i] && str[*i] != ' ')
	{
		if (str[*i] && (str[*i] == '\'' || str[*i] == '"'))
		{
			copy_in_quotes(temp, str, j, i);
			return (temp);
		}
		else if (str[*i] && (str[*i] == '<' || str[*i] == '>'))
			break ;
		else
			temp[j++] = str[(*i)++];
	}
	temp[j] = '\0';
	return (temp);
}

int	count_args( int i, int j)
{
	int	count;

	count = 0;
	while (g_data.cmds[i].cmd && g_data.cmds[i].cmd[j])
	{
		while (g_data.cmds[i].cmd && g_data.cmds[i].cmd[j]
			&& g_data.cmds[i].cmd[j] == ' ')
			j++;
		if (g_data.cmds[i].cmd[j] && is_arg(&g_data.cmds[i].cmd[j], 0, 0))
			count++;
		if (g_data.cmds[i].cmd[j] == '"' || g_data.cmds[i].cmd[j] == '\'')
			j = skip_quotes(g_data.cmds[i].cmd, j);
		while (g_data.cmds[i].cmd[j] && g_data.cmds[i].cmd[j] != ' '
			&& g_data.cmds[i].cmd[j] != '<' && g_data.cmds[i].cmd[j] != '>' )
		{
			if (g_data.cmds[i].cmd[j] == '"' || g_data.cmds[i].cmd[j] == '\'')
				j = skip_quotes(g_data.cmds[i].cmd, j);
			else
				j++;
		}
		j = skip_red(g_data.cmds[i].cmd, j);
	}
	return (count);
}

int	split_arg(int i, int j, int k)
{
	g_data.num_args = count_args(j, 0);
	g_data.args = malloc((g_data.num_args + 1) * sizeof(char *));
	while (g_data.cmds[j].cmd[k])
	{
		while (g_data.cmds[j].cmd[k] && g_data.cmds[j].cmd[k] == ' ')
			k++;
		if (is_arg(&g_data.cmds[j].cmd[k], 0, 0))
			g_data.args[i++] = copy_args(g_data.cmds[j].cmd, &k);
		else if (g_data.cmds[j].cmd[k] == '<' || g_data.cmds[j].cmd[k] == '>')
		{
			if (redirection(&g_data.cmds[j].cmd[k]))
			{
				g_data.args[i] = NULL;
				return (1);
			}
			k = skip_red(g_data.cmds[j].cmd, k);
		}
		while (g_data.cmds[j].cmd[k] && g_data.cmds[j].cmd[k] != ' '
			&& g_data.cmds[j].cmd[k] != '<' && g_data.cmds[j].cmd[k] != '>')
			k++;
	}
	g_data.args[i] = NULL;
	return (0);
}
