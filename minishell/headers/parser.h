/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:07:11 by moukasso          #+#    #+#             */
/*   Updated: 2021/11/04 11:38:10 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

int		int_len(int num);
void	swap_s(char **exit_s);
void	to_char(int exit_v, char **exit_s);
void	change_exit_stat(char **command, int exit_v, int *i, int j);
void	change_var(char **command, char *envp, char **temp, int i);
void	skip_var(char **command, char **temp, int i);
int		change_skip_vars(char **command, char *envp, int len_var, int i);
void	find_vars_env(char **command, char **envp, int *i, int len_var);
void	find_vars_utils(void);
void	find_vars(char **command, char **envp, int i);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		skip_red(char *str, int i);
void	count_vars(char *command, int i, int count);
void	len_var(char *command, int i, int j, int count);
void	is_var_utils(char *command, int *i, int *j, int *count);
void	is_var(char *command, int i, int j, int count);
int		check_between_tok(char *command, int i);
int		check_token(char *command);
int		check_red(char *command);
int		parse_errors(char *command);
int		check_chars(char command);
int		is_arg(char *command, int i, int j);
int		parsing_cmd(int k);
int		skip_quotes(char *str, int k);
int		skip_to_token(char *str, int i);
int		check_closed_quotes(char *str, int i, int doub, int sing);
int		len_of_arg(char *str);
void	copy_in_quotes(char *temp, char *str, int j, int *i);
char	*copy_args(char *str, int *i);
int		count_args( int i, int j);
int		split_arg(int i, int j, int k);
int		count_commands(char *str, char c);
void	split_cmd(char *command, char c);
void	in_ds_quote(char *command, int i, int *doub, int *sing);

#endif