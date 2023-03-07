/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:57:41 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 12:02:29 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	init_data(void)
{
	errno = 0;
	g_data.wait = 0;
	g_data.stopped = 0;
	g_data.cmds_str = NULL;
	g_data.cmds = NULL;
	g_data.args = NULL;
	g_data.vars = NULL;
	g_data.cmd_path = NULL;
	g_data.len_var = NULL;
	g_data.tmpfiles = NULL;
	g_data.cur_tmpfile = NULL;
	g_data.cur_cmd = 0;
	g_data.stdfd[0] = 0;
	g_data.stdfd[1] = 1;
	g_data.str_exit_stat = ft_itoa(g_data.exit_stat);
	tcsetattr(0, TCSANOW, &g_data.edited);
}

void	clear_all_data(int call_exit)
{
	free(g_data.cmds_str);
	free(g_data.cmds);
	free(g_data.vars);
	free(g_data.cmd_path);
	free(g_data.len_var);
	free(g_data.str_exit_stat);
	if (g_data.args)
		free_tab(g_data.args);
	clear_tmpfiles();
	reset_fd();
	if (call_exit)
	{
		tcsetattr(0, TCSANOW, &g_data.origin);
		free_tab(g_data.envp);
		exit(g_data.exit_stat);
	}
}

void	reset_fd(void)
{
	if (g_data.stdfd[0])
	{
		dup2(g_data.stdfd[0], 0);
		close(g_data.stdfd[0]);
	}
	if (g_data.stdfd[1] != 1)
	{
		dup2(g_data.stdfd[1], 1);
		close(g_data.stdfd[1]);
	}
}
