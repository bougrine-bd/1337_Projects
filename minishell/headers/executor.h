/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:30:28 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/06 11:37:07 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H

# define EXECUTOR_H

void	launch_minishell(void);
void	sig_handler(int sig);
void	init_data(void);
void	clear_all_data(int call_exit);
void	reset_fd(void);
int		commands_handler(void);
int		piped_commands(void);
int		piped_commands_support(t_cmds *cmds);
int		duplicate_stdfd(int *dup_stdfd);
int		ft_atoi(char *str, int *err);
char	*ft_itoa(int num);
int		number_of_digits(int num);
char	*extract_filename(char *str);
int		filename_length(char *str);
char	*fill_filename(char *filename, char *str);
char	*extract_delim(char *cmd, int *exp_vars);
int		delim_length(char *cmd);
int		heredoc_readlines(int fd, char *delim, int exp_vars);
char	*heredoc_parse_line(char *str);
int		heredoc_line_length(char *str);
void	launch_piped_command(void);
void	launch_simple_command(void);
void	builtin_command(int builtin_id);
int		parse_command(void);
int		is_builtin(char *cmd);
int		search_command(char *cmd);
int		search_file(char *dir_path, char *file_name);
int		inside_quotes_length(char *str);
int		copy_inside_quotes(char *dst, char *src);
int		quotes_skip(char *str);
int		redirection(char *cmd);
int		redirect_stdin_overwrite(char *file_name);
int		redirect_stdout_overwrite(char *file_name);
int		redirect_stdout_append(char *file_name);
int		heredoc(void);
int		tab_size(char **tab);
void	free_tab(char **tab);
void	sort_tab(char **tab);
char	**dup_tab(char **tab);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcpy(char *dst, char *src);
int		ft_strchr(char *str, char c);
int		skip_spaces(char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char *str, int start, int end);
char	*join_3string(char *s1, char *s2, char *s3);
void	puterr(char *err, int exit_stat);
char	*search_variable(char **envp, char *var);
char	*search_variable_value(char **envp, char *var);
int		variable_name_length(char *var);
int		isvar(char c);
char	*get_cmd_path(char *cmd, char **path_var);
int		search_heredocs(char *cmd);
int		search_heredocs_support(char *cmd);
int		execute_heredoc(char *cmd);
char	*create_new_tmpfile(void);
int		tmpfiles_size(void);
int		add_tmpfile(char *tmpfile);
void	my_wait(void);
int		is_option(char *arg);
char	*ft_strjoin(char *s1, char *s2);
int		cleanup_heredoc_parser(char *delim, int fd, int ret);
void	clear_tmpfiles(void);
void	skip_heredocs(char *cmd);
#endif