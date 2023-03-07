/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:42 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/26 09:17:14 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	export(char **argv)
{
	int	i;
	int	len;

	i = 0;
	if (!g_data.envp)
		return ;
	if (!argv[i + 1])
		display_variables(g_data.envp);
	while (argv[++i])
	{
		len = variable_name_length(argv[i]);
		if (argv[i][len] && argv[i][len] != '=')
			puterr("not a valid identifier", 1);
		else if (update_var(argv[i]))
			continue ;
		else if (set_var(argv[i]))
			puterr(strerror(errno), 1);
	}
}

void	display_variables(char **envp)
{
	int	i;
	int	len;

	i = -1;
	while (envp[++i])
	{
		len = variable_name_length(envp[i]);
		write(1, "declare -x ", 11);
		write(1, envp[i], len);
		if (!envp[i][len])
		{
			write(1, "\n", 1);
			continue ;
		}
		write(1, "=\"", 2);
		write(1, &envp[i][len + 1], ft_strlen(&envp[i][len + 1]));
		write(1, "\"\n", 2);
	}
}

int	update_var(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = variable_name_length(var);
	while (g_data.envp[i] && (variable_name_length(g_data.envp[i]) != len
			|| ft_strncmp(var, g_data.envp[i], len)))
		i++;
	if (!g_data.envp[i])
		return (0);
	if (g_data.envp[i] && !var[len])
		return (1);
	var = ft_strdup(var);
	if (!var)
	{
		puterr(strerror(errno), 1);
		return (1);
	}
	free(g_data.envp[i]);
	g_data.envp[i] = var;
	return (1);
}

int	set_var(char *var)
{
	int		i;
	int		envp_size;
	char	**new_envp;

	i = 0;
	envp_size = tab_size(g_data.envp);
	new_envp = malloc((envp_size + 2) * sizeof(char *));
	if (!new_envp)
		return (1);
	while (g_data.envp[i])
	{
		new_envp[i] = g_data.envp[i];
		i++;
	}
	new_envp[i] = ft_strdup(var);
	if (!new_envp[i])
		return (1);
	new_envp[i + 1] = NULL;
	sort_tab(new_envp);
	free(g_data.envp);
	g_data.envp = new_envp;
	return (0);
}
