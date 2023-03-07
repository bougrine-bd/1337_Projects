/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:09:35 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 11:54:01 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	piped_commands(void)
{
	int	dup_stdfd[2];

	if (duplicate_stdfd(dup_stdfd)
		|| piped_commands_support(g_data.cmds))
		return (1);
	dup2(dup_stdfd[1], 1), close(dup_stdfd[1]), g_data.stdfd[1] = 1;
	if (!parse_command())
	{
		g_data.last_cmd_pid = fork();
		if (g_data.last_cmd_pid == -1)
			return (1);
		if (g_data.last_cmd_pid == 0)
			launch_piped_command();
	}
	dup2(dup_stdfd[0], 0), close(dup_stdfd[0]), g_data.stdfd[0] = 0;
	g_data.cur_cmd++;
	return (0);
}

int	piped_commands_support(t_cmds *cmds)
{
	int	pid;
	int	pipe_fd[2];

	while (cmds[g_data.cur_cmd].tok == '|')
	{
		if (pipe(pipe_fd) < 0)
			return (1);
		dup2(pipe_fd[1], 1), close(pipe_fd[1]);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			close(pipe_fd[0]);
			if (!parse_command())
				launch_piped_command();
			exit(g_data.exit_stat);
		}
		dup2(pipe_fd[0], 0), close(pipe_fd[0]);
		skip_heredocs(cmds[g_data.cur_cmd].cmd);
		g_data.cur_cmd++;
	}
	return (0);
}

int	duplicate_stdfd(int *dup_stdfd)
{
	dup_stdfd[0] = dup(0);
	dup_stdfd[1] = dup(1);
	if (dup_stdfd[0] < 0 || dup_stdfd[1] < 0)
		return (1);
	g_data.stdfd[0] = dup_stdfd[0];
	g_data.stdfd[1] = dup_stdfd[1];
	return (0);
}
