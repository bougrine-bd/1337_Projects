/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 02:46:56 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/03 11:56:19 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	redirection(char *cmd)
{
	int		ret;
	char	*str;

	if (*cmd == '<' && *(cmd + 1) == '<')
	{
		ret = redirect_stdin_overwrite(g_data.cur_tmpfile->path);
		g_data.cur_tmpfile = g_data.cur_tmpfile->next;
		return (ret);
	}
	if (*cmd == '>' && *(cmd + 1) == '>')
		str = extract_filename(cmd + 2);
	else
		str = extract_filename(cmd + 1);
	if (!str)
		return (1);
	else if (*cmd == '>' && *(cmd + 1) == '>')
		ret = redirect_stdout_append(str);
	else if (*cmd == '>')
		ret = redirect_stdout_overwrite(str);
	else
		ret = redirect_stdin_overwrite(str);
	free(str);
	return (ret);
}

int	redirect_stdin_overwrite(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, S_IRWXU);
	if (fd < 0)
	{
		puterr(strerror(errno), 1);
		return (1);
	}
	if (g_data.stdfd[0] == 0)
	{
		g_data.stdfd[0] = dup(0);
		if (g_data.stdfd[0] < 0)
		{
			puterr(strerror(errno), 1);
			return (1);
		}
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	redirect_stdout_overwrite(char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		puterr(strerror(errno), 1);
		return (1);
	}
	if (g_data.stdfd[1] == 1)
	{
		g_data.stdfd[1] = dup(1);
		if (g_data.stdfd[1] < 0)
		{
			puterr(strerror(errno), 1);
			return (1);
		}
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	redirect_stdout_append(char *file_name)
{
	int	fd;

	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (fd < 0)
	{
		puterr(strerror(errno), 1);
		return (1);
	}
	if (g_data.stdfd[1] == 1)
	{
		g_data.stdfd[1] = dup(1);
		if (g_data.stdfd[1] < 0)
		{
			puterr(strerror(errno), 1);
			return (1);
		}
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}
