/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:53:24 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/02 08:49:59 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	change_skip_vars(char **command, char *envp, int len_var, int i)
{
	char	*temp;
	int		sum;
	int		j;

	j = 0;
	if (envp)
	{
		while (envp[j] && envp[j] != '=')
			j++;
		sum = ft_strlen(*command) - (len_var + 1) + ft_strlen(&envp[++j]);
		temp = malloc(sum + 1);
		change_var(command, &envp[j], &temp, i);
		free(*command);
		*command = temp;
		return (ft_strlen(&envp[j]));
	}
	else
	{
		sum = ft_strlen(*command) - (len_var + 1);
		temp = malloc(sum + 1);
		skip_var(command, &temp, i);
		free(*command);
		*command = temp;
	}
	return (ft_strlen(*command) - sum);
}

void	find_vars_env(char **command, char **envp, int *i, int len_var)
{
	int		j;
	int		sum;

	j = 0;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], &(*command)[*i], len_var) == -1)
			j++;
		else if (envp[j][len_var] != '=')
			j++;
		else
			break ;
	}
	sum = change_skip_vars(command, envp[j], len_var, (*i) - 1);
	(*i) = (*i) - 1 + sum;
}

void	find_vars_utils(void)
{
	if (g_data.vars[g_data.var_index] == 1
		&& g_data.len_var[g_data.var_index] == 0)
		while (g_data.vars[g_data.var_index] == 1
			&& g_data.len_var[g_data.var_index] == 0)
			g_data.var_index++;
	else
		g_data.var_index++;
}

void	find_vars(char **command, char **envp, int i)
{
	while ((*command)[i])
	{
		if ((*command)[i] == '$')
		{
			i++;
			if (g_data.vars[g_data.var_index] == 1
				&& g_data.len_var[g_data.var_index] != 0)
			{
				if ((*command)[i] == '?')
					change_exit_stat(command, g_data.exit_stat, &i, 0);
				else
					find_vars_env(command, envp, &i,
						g_data.len_var[g_data.var_index]);
			}
			find_vars_utils();
		}
		else
			i++;
		if (g_data.var_index == g_data.vars_num)
			break ;
		if (i && (*command)[i - 1] == '$'
			&& g_data.vars[g_data.var_index - 1] == 1
			&& g_data.len_var[g_data.var_index - 1] == 0)
			i--;
	}
}
