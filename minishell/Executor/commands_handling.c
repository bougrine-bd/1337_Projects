/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 09:13:28 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/04 12:34:46 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	commands_handler(void)
{
	g_data.wait = 1;
	if (g_data.num_cmd > 1)
	{
		if (piped_commands())
			return (1);
		my_wait();
	}
	else
	{
		if (!parse_command())
		{
			launch_simple_command();
			my_wait();
		}
		g_data.cur_cmd++;
	}
	return (0);
}

void	my_wait(void)
{
	int				ret;
	int				wstatus;
	int				exit_stat;
	unsigned int	sig;

	while (1)
	{
		ret = wait(&wstatus);
		if (ret == -1)
			break ;
		sig = wstatus & 0x7F;
		if (sig)
		{
			exit_stat = 128 + sig;
			if (sig != SIGPIPE)
				g_data.new_line = 1;
		}
		else
			exit_stat = wstatus >> 8;
		if (ret == g_data.last_cmd_pid)
			g_data.exit_stat = exit_stat;
	}
}
