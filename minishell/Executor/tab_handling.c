/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:25:14 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/19 17:17:53 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	if (!tab[i])
		return ;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

char	**dup_tab(char **tab)
{
	int		i;
	int		size;
	char	**new_tab;

	i = -1;
	size = tab_size(tab);
	new_tab = malloc((size + 1) * sizeof(char **));
	if (!new_tab)
	{
		puterr(strerror(errno), 1);
		return (NULL);
	}
	while (tab[++i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
		{
			free_tab(new_tab);
			return (NULL);
		}
	}
	new_tab[i] = NULL;
	return (new_tab);
}
