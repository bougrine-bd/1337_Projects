/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:04:48 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/26 14:01:38 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_catstr(char const *src1, char const *src2, char *dest)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (src1[++i] != '\0')
		dest[i] = src1[i];
	while (src2[j] != '\0')
		dest[i++] = src2[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	s3 = malloc(i + j + 1);
	if (s3 == NULL)
		return (NULL);
	return (ft_catstr(s1, s2, s3));
}
