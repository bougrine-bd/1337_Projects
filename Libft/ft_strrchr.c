/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:30:46 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 20:49:19 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i)
	{
		if (str[i] == (char)c)
			return ((char*)(str + i));
		i--;
	}
	if (str[i] == (char)c)
		return ((char*)(str + i));
	return (0);
}
