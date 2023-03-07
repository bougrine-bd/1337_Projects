/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:14:31 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 19:02:58 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cstr;
	size_t			i;

	cstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == (unsigned char)c)
			return (cstr + i);
		i++;
	}
	return (0);
}
