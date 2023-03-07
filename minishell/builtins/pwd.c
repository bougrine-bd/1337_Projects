/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:37:40 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/19 17:19:50 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

void	pwd(void)
{
	char	*buff;

	buff = NULL;
	buff = getcwd(buff, 1024);
	if (!buff)
		puterr(strerror(errno), 1);
	write(1, buff, ft_strlen(buff));
	write(1, "\n", 1);
	free(buff);
}
