/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:59:01 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/03 11:28:15 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	launch_piped_command(void)
{
	g_data.wait = 0;
	if (g_data.builtin_id)
	{
		builtin_command(g_data.builtin_id);
		exit(g_data.exit_stat);
	}
	execve(g_data.cmd_path, g_data.args, g_data.envp);
	if (errno == ENOENT)
		puterr(strerror(errno), 127);
	else
		puterr(strerror(errno), 126);
	exit(g_data.exit_stat);
}

void	launch_simple_command(void)
{
	int	pid;

	if (g_data.builtin_id)
	{
		builtin_command(g_data.builtin_id);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		puterr(strerror(errno), 1);
		return ;
	}
	else if (pid == 0)
	{
		g_data.wait = 0;
		execve(g_data.cmd_path, g_data.args, g_data.envp);
		if (errno == ENOENT)
			puterr(strerror(errno), 127);
		else
			puterr(strerror(errno), 126);
		exit(g_data.exit_stat);
	}
	g_data.last_cmd_pid = pid;
}

void	builtin_command(int builtin_id)
{
	if (builtin_id == 1)
		echo(g_data.args);
	else if (builtin_id == 2)
		cd(g_data.args);
	else if (builtin_id == 3)
		pwd();
	else if (builtin_id == 4)
		export(g_data.args);
	else if (builtin_id == 5)
		unset(g_data.args);
	else if (builtin_id == 6)
		env(g_data.envp);
	else if (builtin_id == 7)
		exit_msh(g_data.args);
}
