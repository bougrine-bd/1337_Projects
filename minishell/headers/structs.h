/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:50:40 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 09:44:13 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_cmds
{
	char	*cmd;
	char	tok;
}t_cmds;

typedef struct s_tmpfiles
{
	char				*path;
	struct s_tmpfiles	*next;
}t_tmpfiles;

typedef struct s_data
{
	struct termios	origin;
	struct termios	edited;
	int				wait;
	int				heredoc;
	int				stopped;
	int				new_line;
	char			*cmds_str;
	t_cmds			*cmds;
	char			**envp;
	char			**args;
	int				*vars;
	char			*cmd_path;
	int				cur_cmd;
	int				num_cmd;
	int				num_args;
	int				vars_num;
	int				var_index;
	int				*len_var;
	int				last_cmd_pid;
	int				builtin_id;
	int				stdfd[2];
	int				exit_stat;
	char			*str_exit_stat;
	t_tmpfiles		*tmpfiles;
	t_tmpfiles		*cur_tmpfile;
}t_data;

#endif