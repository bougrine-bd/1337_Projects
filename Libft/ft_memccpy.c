/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:15:20 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 19:02:43 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	while (i < n)
	{
		cdest[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
		{
			i++;
			return (cdest + i);
		}
		i++;
	}
	return (0);
}
