/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:57:36 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/29 09:55:07 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	if (!(dest) && !(src))
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	cdest = (char *)dest;
	csrc = (char *)src;
	i = (dest > src) ? dest - src : 0;
	if (dest == (src + i) && dest > src && n > 0)
	{
		while (n-- > 0)
			cdest[n] = csrc[n];
		return (cdest);
	}
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
