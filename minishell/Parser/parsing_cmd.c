/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:56:22 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/06 12:41:11 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	find_env(char *command, int i, int j, int len_var)
{
	while (g_data.envp[j])
	{
		if (ft_strncmp(g_data.envp[j], &command[i - len_var], len_var) == -1)
			j++;
		else if (g_data.envp[j][len_var] != '=')
			j++;
		else
			break ;
	}
	return (j);
}

int	is_arg(char *command, int i, int j)
{
	int	len_var;

	if (command[i] == '<' || command[i] == '>')
		return (0);
	while (command[i] && command[i] != ' ')
	{
		j = 0;
		len_var = 0;
		if (command[i] == '$' && check_chars(command[i + 1]))
		{
			while (command[++i] && check_chars(command[i]))
				len_var++;
			j = find_env(command, i, j, len_var);
			if (g_data.envp[j])
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	parsing_cmd(int k)
{
	int	i;

	i = 0;
	g_data.var_index = 0;
	if (!g_data.cmds[k].cmd)
		return (0);
	is_var(g_data.cmds[k].cmd, 0, 0, 0);
	if (split_arg(0, k, 0))
		return (1);
	while (i < g_data.num_args)
	{
		find_vars(&g_data.args[i], g_data.envp, 0);
		i++;
	}
	if (i == 0)
		g_data.exit_stat = 0;
	return (0);
}
