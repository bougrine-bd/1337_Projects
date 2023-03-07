/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:57:34 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 20:31:35 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;

	if (!(*find))
		return ((char *)str);
	if (n == 0)
		return (NULL);
	while (*str && n > 0)
	{
		i = 0;
		while (str[i] == find[i] && i < n)
		{
			i++;
			if (find[i] == '\0')
				return ((char *)str);
		}
		str++;
		n--;
	}
	return (0);
}
