/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:41:09 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 10:27:24 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_nblen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
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
	free(str);
	free(toa);
	return (toa);
}

char	*ft_itoa(long n)
{
	char	*toa;
	long	nbr;
	int		itoa_len;
	int		i;

	i = 0;
	nbr = n;
	itoa_len = ft_nblen(nbr);
	toa = malloc(itoa_len * sizeof(char) + 1);
	if (toa == NULL)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	toa[i++] = nbr % 10 + 48;
	while ((nbr /= 10) > 0)
		toa[i++] = nbr % 10 + 48;
	toa[i] = '\0';
	return (ft_rev(toa, ft_strlen(toa)));
}
