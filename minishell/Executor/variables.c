/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 02:09:08 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/26 09:10:31 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

char	*search_variable(char **envp, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = variable_name_length(var);
	if (!envp)
		return (NULL);
	while (envp[i] && (variable_name_length(envp[i]) != len
			|| ft_strncmp(envp[i], var, len)))
		i++;
	return (envp[i]);
}

char	*search_variable_value(char **envp, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = variable_name_length(var);
	if (*var == '?')
		return (g_data.str_exit_stat);
	if (!envp)
		return (NULL);
	while (envp[i] && (variable_name_length(envp[i]) != len
			|| ft_strncmp(envp[i], var, len)))
		i++;
	if (!envp[i])
		return (NULL);
	return (&envp[i][len + 1]);
}

int	variable_name_length(char *var)
{
	int	length;

	length = 0;
	if (var[length] == '?')
		return (1);
	while ((var[length] >= 'a' && var[length] <= 'z')
		|| (var[length] >= 'A' && var[length] <= 'Z')
		|| (var[length] >= '0' && var[length] <= '9')
		|| var[length] == '_')
		length++;
	return (length);
}

int	isvar(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| c == '_' || c == '?')
		return (1);
	return (0);
}
