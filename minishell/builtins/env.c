/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:47 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/19 17:19:50 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strchr(envp[i], '='))
			continue ;
		write(1, envp[i], ft_strlen(envp[i]));
		write(1, "\n", 1);
	}
}
