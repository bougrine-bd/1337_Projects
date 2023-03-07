/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:11:53 by abougrin          #+#    #+#             */
/*   Updated: 2021/11/07 07:50:55 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	check_between_tok(char *command, int i)
{
	int	count;

	count = 0;
	while (command[i] && command[i] != '|')
	{
		if (command[i] != ' ' && command[i] != '|')
			count++;
		i++;
	}
	if (count == 0 || (command[i] == '|' && !command[i + 1]))
		return (-1);
	return (0);
}

int	check_token(char *command)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (command[i] && command[i] != '|')
	{
		if (command[i] != ' ')
			j++;
		i++;
	}
	if (command[i] == '|' )
	{
		if (j == 0 || command[++i] == '|'
			|| check_between_tok(command, i) == -1)
		{
			g_data.exit_stat = 258;
			write(2, "ERROR : Syntax error near unexpected token\n", 43);
			return (-1);
		}
	}	
	return (0);
}

int	check_red_utils(char *command, int i, int *count)
{
	if (command[i] == '>')
	{
		if (command[++i] == '<')
			(*count)++;
		else if (command[i] == '>')
			i++;
		while (command[i] == ' ')
			i++;
		if (command[i] == '<' || command[i] == '>' || !command[i])
			(*count)++;
	}
	else if (command[i] == '<')
	{
		if (command[++i] == '>')
			(*count)++;
		else if (command[i] == '<')
			i++;
		while (command[i] == ' ')
			i++;
		if (command[i] == '<' || command[i] == '>' || !command[i])
			(*count)++;
	}
	return (i);
}

int	check_red(char *command)
{
	int	i;
	int	count;
	int	doub;
	int	sing;

	sing = 0;
	doub = 0;
	count = 0;
	i = -1;
	while (command[++i])
	{
		in_ds_quote(command, i, &doub, &sing);
		if ((command[i] == '>' || command[i] == '<') && doub == 0 && sing == 0)
			check_red_utils(command, i, &count);
	}
	if (count != 0)
	{
		g_data.exit_stat = 258;
		write(2, "ERROR : Syntax error near unexpected token\n", 43);
		return (-1);
	}
	return (0);
}

int	parse_errors(char *command)
{
	if (check_closed_quotes(command, 0, 0, 0) == -1)
		return (-1);
	if (check_token(command) == -1)
		return (-1);
	if (check_red(command) == -1)
		return (-1);
	return (0);
}
