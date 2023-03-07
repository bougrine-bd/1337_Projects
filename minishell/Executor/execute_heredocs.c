/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 07:38:13 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 12:07:49 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	search_heredocs(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && !g_data.stopped)
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			i += quotes_skip(&cmd[i]);
		else if (cmd[i] == '>' || (cmd[i] == '<' && cmd[i + 1] != '<'))
			i += skip_red(&cmd[i], 0);
		else if (cmd[i] == '<')
		{
			if (execute_heredoc(&cmd[i]))
			{
				puterr(strerror(errno), 1);
				return (1);
			}
			i += skip_red(&cmd[i], 0);
		}
		else
			i++;
	}
	g_data.cur_tmpfile = g_data.tmpfiles;
	return (g_data.stopped);
}

int	execute_heredoc(char *cmd)
{
	int		fd;
	int		exp_vars;
	char	*tmpfile;
	char	*delim;

	exp_vars = 1;
	tmpfile = create_new_tmpfile();
	delim = extract_delim((cmd + 2), &exp_vars);
	if (!tmpfile || !delim)
		return (1);
	fd = open(tmpfile, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
	if (fd < 0)
		return (cleanup_heredoc_parser(delim, -1, 1));
	if (heredoc_readlines(fd, delim, exp_vars))
		return (cleanup_heredoc_parser(delim, fd, 1));
	return (cleanup_heredoc_parser(delim, fd, 0));
}

int	cleanup_heredoc_parser(char *delim, int fd, int ret)
{	
	free(delim);
	if (fd >= 0)
		close(fd);
	return (ret);
}

void	skip_heredocs(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '\'' || *cmd == '"')
			cmd += quotes_skip(cmd);
		else if (*cmd == '<' && *(cmd + 1) == '<')
		{
			cmd += skip_red(cmd, 0);
			g_data.cur_tmpfile = g_data.cur_tmpfile->next;
		}
		else
			cmd++;
	}
}
