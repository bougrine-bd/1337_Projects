/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:37 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/07 08:12:12 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	echo(char **argv)
{
	int	i;
	int	new_line;

	i = 1;
	if (!argv[1])
		return (echo_return(1));
	new_line = !(is_option(argv[1]));
	if (!new_line)
	{
		i++;
		while (argv[i] && is_option(argv[i]))
			i++;
	}
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
		if (argv[i])
			write(1, " ", 1);
	}
	return (echo_return(new_line));
}

int	is_option(char *arg)
{
	int	i;
	int	true;

	i = 0;
	true = 0;
	if (arg[0] == '-')
	{
		while (arg[++i] == 'n')
			true = 1;
	}
	if (arg[i])
		return (0);
	return (true);
}

void	echo_return(int new_line)
{
	if (new_line)
		write(1, "\n", 1);
	return ;
}
