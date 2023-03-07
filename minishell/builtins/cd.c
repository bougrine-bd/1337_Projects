/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:33 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/19 17:19:55 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	cd(char **argv)
{
	if (argv[1])
	{
		if (chdir(argv[1]) == -1)
			puterr(strerror(errno), 1);
	}
}
