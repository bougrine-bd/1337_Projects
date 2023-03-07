/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_exit_stat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:19:49 by abougrin          #+#    #+#             */
/*   Updated: 2021/10/25 10:27:59 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	int_len(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	swap_s(char **exit_s)
{
	char	*start;
	int		i;
	int		j;

	j = ft_strlen(*exit_s);
	start = malloc(j + 1);
	i = 0;
	while (j)
		start[i++] = (*exit_s)[--j];
	start[i] = '\0';
	free(*exit_s);
	*exit_s = start;
}

void	to_char(int exit_v, char **exit_s)
{
	int		i;

	i = 0;
	*exit_s = malloc(int_len(exit_v) + 1);
	if (!exit_v)
		(*exit_s)[i++] = '0';
	while (exit_v)
	{
		(*exit_s)[i] = '0' + (exit_v % 10);
		exit_v /= 10;
		i++;
	}
	(*exit_s)[i] = '\0';
	swap_s(exit_s);
}

void	change_exit_stat(char **command, int exit_v, int *i, int j)
{
	char	*exit_s;
	char	*temp;
	int		k;
	int		l;

	l = 0;
	k = 0;
	to_char(exit_v, &exit_s);
	temp = malloc((ft_strlen(*command) - 2 + ft_strlen(exit_s)) + 1);
	while ((*command)[l])
	{
		if (j == *i - 1)
		{
			l += 2;
			while (exit_s[k])
				temp[j++] = exit_s[k++];
		}
		else
			temp[j++] = (*command)[l++];
	}
	temp[j] = '\0';
	free(*command);
	*command = temp;
	*i = *i - 2 + ft_strlen(exit_s);
	free(exit_s);
}
