/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:54:37 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/20 07:20:10 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H

void	cd(char **argv);
void	echo(char **argv);
void	echo_return(int new_line);
void	env(char **envp);
void	exit_msh(char **argv);
void	export(char **argv);
void	display_variables(char **envp);
int		update_var(char *var);
int		set_var(char *var);
void	pwd(void);
void	unset(char **argv);
int		unset_var(char *var);

#endif