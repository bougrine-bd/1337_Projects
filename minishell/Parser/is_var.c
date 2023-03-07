/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:53:37 by abougrin          #+#    #+#             */
/*   Updated: 2021/10/28 11:19:14 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	in_ds_quote(char *command, int i, int *doub, int *sing)
{
	if (command[i] == '"' && *doub == 0)
		*doub = 1;
	else if (command[i] == '"' && *doub == 1)
		*doub = 0;
	if (command[i] == '\'' && *sing == 0 && *doub == 0)
		*sing = 1;
	else if (command[i] == '\'' && *sing == 1)
		*sing = 0;
}

void	count_vars(char *command, int i, int count)
{
	int	doub;
	int	sing;

	sing = 0;
	doub = 0;
	while (command && command[i])
	{
		in_ds_quote(command, i, &doub, &sing);
		if ((command[i] == '>' || command[i] == '<') && doub == 0 && sing == 0)
			i = skip_red(command, i);
		else if (command[i++] == '$')
			count++;
	}
	g_data.vars = malloc(count * sizeof(int));
	g_data.len_var = malloc(count * sizeof(int));
	i = -1;
	while (++i < count)
	{
		g_data.vars[i] = 0;
		g_data.len_var[i] = 0;
	}
	g_data.vars_num = count;
}

void	len_var(char *command, int i, int j, int count)
{
	int	len;

	len = 0;
	if (is_arg(&command[j], 0, 0))
		while (command[++i]
			&& (check_chars(command[i]) == 1 || command[i] == '?'))
			len++;
	g_data.len_var[count] = len;
}

void	is_var_utils(char *command, int *i, int *j, int *count)
{
	if (command[*i] == '$' && command[*i + 1] == '$')
	{
		g_data.vars[(*count)++] = 0;
		g_data.vars[(*count)++] = 0;
		(*i) += 2;
	}
	else if (command[*i] == '$' && check_chars(command[*i + 1]) == 0
		&& command[*i + 1] != '?')
	{
		g_data.vars[(*count)++] = 0;
		(*i)++;
	}
	else if (command[*i] == '$')
	{
		g_data.vars[(*count)++] = 1;
		len_var(command, *i, *j, (*count - 1));
		(*i)++;
	}
}

void	is_var(char *command, int i, int j, int count)
{
	int	doub;
	int	sing;

	sing = 0;
	doub = 0;
	count_vars(command, 0, 0);
	while (command[i])
	{
		in_ds_quote(command, i, &doub, &sing);
		if ((command[i] == '>' || command[i] == '<') && doub == 0 && sing == 0)
			i = skip_red(command, i);
		else if (command[i] == '\'' && doub == 0)
		{
			while (command[i] && command[++i] != '\'')
				if (command[i] == '$')
					g_data.vars[count++] = 0;
			i++;
		}
		else if (command[i] == '$')
			is_var_utils(command, &i, &j, &count);
		else
			i++;
		if (command[i] == ' ' && doub == 0)
			j = i + 1;
	}
}
