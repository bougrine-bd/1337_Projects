/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:44:10 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/27 20:24:29 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cs;
	size_t	i;
	size_t	k;
	int		j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	cs = malloc(len + 1);
	if (cs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < start + 1)
		i++;
	i--;
	while (k++ < len)
		cs[j++] = s[i++];
	cs[j] = '\0';
	return (cs);
}
