/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_vars_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:44:17 by abougrin          #+#    #+#             */
/*   Updated: 2021/10/28 15:28:09 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	change_var(char **command, char *envp, char **temp, int i)
{
	int	j;
	int	k;
	int	x;

	x = 0;
	k = 0;
	j = 0;
	while ((*command)[x])
	{
		if (x == i)
		{
			x += g_data.len_var[g_data.var_index] + 1;
			while (envp[k])
				(*temp)[j++] = envp[k++];
		}
		else
			(*temp)[j++] = (*command)[x++];
	}
	(*temp)[j] = '\0';
}

void	skip_var(char **command, char **temp, int i)
{
	int	j;
	int	x;

	x = 0;
	j = 0;
	while ((*command)[x])
	{
		if (x == i)
			x += g_data.len_var[g_data.var_index] + 1;
		else
			(*temp)[j++] = (*command)[x++];
	}
	(*temp)[j] = '\0';
}
