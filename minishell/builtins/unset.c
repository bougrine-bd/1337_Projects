/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:45 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/07 09:06:29 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	unset(char **argv)
{
	int		i;
	int		len;

	i = 1;
	if (!g_data.envp)
		return ;
	while (argv[i])
	{
		len = variable_name_length(argv[i]);
		if (argv[i][len])
			puterr("not a valid identifier", 1);
		else if (search_variable(g_data.envp, argv[i]))
		{
			if (unset_var(argv[i]))
				puterr(strerror(errno), errno);
		}
		i++;
	}
}

int	unset_var(char *var)
{
	int		i;
	int		len;
	int		envp_size;
	char	**new_envp;

	i = -1;
	len = variable_name_length(var);
	envp_size = tab_size(g_data.envp);
	new_envp = malloc(envp_size * sizeof(char *));
	if (!new_envp)
		return (1);
	while (ft_strncmp(g_data.envp[++i], var, len))
		new_envp[i] = g_data.envp[i];
	free(g_data.envp[i]);
	while (g_data.envp[i + 1])
	{
		new_envp[i] = g_data.envp[i + 1];
		i++;
	}
	new_envp[i] = NULL;
	free(g_data.envp);
	g_data.envp = new_envp;
	return (0);
}
