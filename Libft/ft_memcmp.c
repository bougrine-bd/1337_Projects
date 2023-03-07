/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:32:44 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 14:10:30 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;
	int				i;

	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	i = 0;
	while (n > 0)
	{
		if (cstr1[i] != cstr2[i])
			return (cstr1[i] - cstr2[i]);
		n--;
		i++;
	}
	return (0);
}
