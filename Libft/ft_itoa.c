/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:22:15 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/23 14:11:45 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_itoa_len(long n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_rev(char *str, int len)
{
	char	*toa;
	int		i;
	int		j;

	toa = malloc(ft_strlen(str) + 1);
	if (toa == NULL)
		return (NULL);
	i = 0;
	j = len - 1;
	while (i < len)
		toa[i++] = str[j--];
	toa[i] = '\0';
	return (toa);
}

char	*ft_itoa(int n)
{
	char	*toa;
	long	nbr;
	int		itoa_len;
	int		i;

	i = 0;
	nbr = n;
	itoa_len = ft_itoa_len(nbr);
	toa = malloc(itoa_len * sizeof(char) + 1);
	if (toa == NULL)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	toa[i++] = nbr % 10 + 48;
	while ((nbr /= 10) > 0)
		toa[i++] = nbr % 10 + 48;
	if (n < 0)
		toa[i++] = '-';
	toa[i] = '\0';
	return (ft_rev(toa, ft_strlen(toa)));
}
