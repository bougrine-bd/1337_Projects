/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:12:22 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 12:01:15 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	exit_msh(char **argv)
{
	int	err;

	err = 0;
	if (argv[1])
		g_data.exit_stat = ft_atoi(argv[1], &err);
	if (err)
	{
		puterr("numeric argument required", 255);
		clear_all_data(1);
	}
	else if (argv[1] && argv[2])
	{
		puterr("too many arguments", 1);
		return ;
	}
	clear_all_data(1);
}
