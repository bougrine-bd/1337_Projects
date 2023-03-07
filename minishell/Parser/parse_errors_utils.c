/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_section.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:23:48 by abougrin          #+#    #+#             */
/*   Updated: 2021/10/24 16:06:03 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	check_closed_quotes(char *str, int i, int doub, int sing)
{
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (str[i] == '"' && doub == 0 && sing == 0)
				doub = 1;
			else if (str[i] == '\'' && sing == 0 && doub == 0)
				sing = 2;
			else if (str[i] == '"' && doub == 1)
				doub = 0;
			else if (str[i] == '\'' && sing == 2)
				sing = 0;
			i++;
		}
		else
			i++;
	}
	if (doub == 1 || sing == 2)
	{
		g_data.exit_stat = 258;
		write(2, "Error : quote not closed\n", 25);
		return (-1);
	}
	return (0);
}
