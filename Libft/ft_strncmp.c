/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:41:01 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/23 22:06:49 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	unsigned int	i;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((cs1[i] || cs2[i]) && i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		else
			i++;
	}
	return (0);
}
