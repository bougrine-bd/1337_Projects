/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:20:15 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 10:41:32 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	parse_command(void)
{
	int	ret;

	ret = 0;
	if (parsing_cmd(g_data.cur_cmd))
		return (1);
	if (!g_data.args || !g_data.args[0])
		return (1);
	g_data.builtin_id = is_builtin(g_data.args[0]);
	if (g_data.builtin_id != 7)
		g_data.exit_stat = 0;
	if (g_data.builtin_id)
		return (0);
	else if (ft_strchr(g_data.args[0], '/'))
	{
		g_data.cmd_path = ft_strdup(g_data.args[0]);
		if (!g_data.cmd_path)
			ret = -1;
	}
	else
		ret = search_command(g_data.args[0]);
	if (ret < 0)
		puterr(strerror(errno), 1);
	else if (ret)
		puterr("Command not found", 127);
	return (ret);
}

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (2);
	if (!ft_strcmp(cmd, "pwd"))
		return (3);
	if (!ft_strcmp(cmd, "export"))
		return (4);
	if (!ft_strcmp(cmd, "unset"))
		return (5);
	if (!ft_strcmp(cmd, "env"))
		return (6);
	if (!ft_strcmp(cmd, "exit"))
		return (7);
	return (0);
}

int	search_command(char *cmd)
{
	char		*cmd_path;
	char		*path_var;
	struct stat	buf;

	path_var = search_variable_value(g_data.envp, "PATH");
	if (!path_var || !(*path_var))
	{
		g_data.cmd_path = ft_strdup(g_data.args[0]);
		if (!g_data.cmd_path)
			return (-1);
		return (0);
	}
	while (*path_var)
	{
		cmd_path = get_cmd_path(cmd, &path_var);
		if (!cmd_path)
			return (-1);
		if (!stat(cmd_path, &buf) && !S_ISDIR(buf.st_mode))
		{
			g_data.cmd_path = cmd_path;
			return (0);
		}
		free(cmd_path);
	}
	return (1);
}

char	*get_cmd_path(char *cmd, char **path_var)
{
	int		i;
	char	*dir_path;
	char	*cmd_path;

	i = 0;
	while ((*path_var)[i] && (*path_var)[i] != ':')
		i++;
	dir_path = ft_substr((*path_var), 0, i);
	if (!(dir_path))
		return (NULL);
	cmd_path = join_3string(dir_path, "/", cmd);
	free(dir_path);
	if (!(cmd_path))
		return (NULL);
	(*path_var) += i;
	if (**path_var)
		(*path_var)++;
	return (cmd_path);
}
