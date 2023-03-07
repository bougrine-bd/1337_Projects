/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:49:14 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/07 09:12:41 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_data	g_data;

void	sig_handler(int sig)
{
	if (sig == 2 && !g_data.wait)
	{
		g_data.stopped = 1;
		g_data.exit_stat = 1;
		rl_on_new_line();
		write(1, "\n", 1);
		ioctl(0, TIOCSTI, "\x04");
	}
}

void	launch_minishell(void)
{
	while (1)
	{
		init_data();
		if (g_data.new_line)
			write(1, "\n", 1);
		g_data.new_line = 0;
		g_data.cmds_str = readline("Msh-9255h$ ");
		if (!g_data.cmds_str)
		{
			clear_all_data(!g_data.stopped);
			continue ;
		}
		if (*g_data.cmds_str)
			add_history(g_data.cmds_str);
		if (!parse_errors(g_data.cmds_str)
			&& !search_heredocs(g_data.cmds_str))
		{
			tcsetattr(0, TCSANOW, &g_data.origin);
			split_cmd(g_data.cmds_str, '|');
			if (commands_handler())
				puterr(strerror(errno), 1);
		}
		clear_all_data(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	argc = 0;
	argv = NULL;
	signal(SIGQUIT, sig_handler);
	signal(SIGINT, sig_handler);
	tcgetattr(0, &g_data.origin);
	g_data.edited = g_data.origin;
	g_data.edited.c_cc[VQUIT] = 254;
	if (envp)
	{
		g_data.envp = dup_tab(envp);
		if (!g_data.envp)
			exit(1);
		sort_tab(g_data.envp);
	}
	else
	{
		g_data.envp = malloc(sizeof(char *));
		if (!g_data.envp)
			exit(1);
		g_data.envp[0] = NULL;
	}
	g_data.exit_stat = 0;
	g_data.new_line = 0;
	launch_minishell();
}
