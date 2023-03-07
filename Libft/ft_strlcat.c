/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:54:33 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/29 09:58:56 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lsrc;
	size_t	ldest;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	lsrc = ft_strlen(src);
	ldest = ft_strlen(dest);
	i = 0;
	if (ldest < size)
		lsrc = lsrc + ldest;
	else if (ldest >= size)
		lsrc = lsrc + size;
	while (src[i] && ldest < size - 1)
		dest[ldest++] = src[i++];
	if (ldest < size)
		dest[ldest] = '\0';
	return (lsrc);
}
