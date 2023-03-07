/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:28:55 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/23 14:27:40 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		j;

	str = (char *)s;
	i = 0;
	if (!(s) || !(f))
		return (NULL);
	while (str[i])
		i++;
	str = malloc(i * sizeof(*s) + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
