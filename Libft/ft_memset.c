/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:58:04 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 16:57:30 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*cstr;

	cstr = (unsigned char *)str;
	while (len > 0)
	{
		*cstr = (unsigned char)c;
		cstr++;
		len--;
	}
	return (str);
}
