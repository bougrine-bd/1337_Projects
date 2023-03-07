/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:31:56 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/15 17:32:38 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msleep(size_t end)
{
	struct timeval	t;
	size_t			now;
	size_t			start;

	gettimeofday(&t, NULL);
	start = (t.tv_sec * 1000000) + t.tv_usec;
	now = start;
	while ((now - start) <= end)
	{
		usleep(100);
		gettimeofday(&t, NULL);
		now = (t.tv_sec * 1000000) + t.tv_usec;
	}
}

int	gmtb(size_t start)
{
	int				sum;
	size_t			now;
	struct timeval	t;

	gettimeofday(&t, NULL);
	now = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	sum = now - start;
	return (sum);
}

long	toint(char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res < 0 && sign > 0)
			return (-1);
		if (res < 0 && sign < 0)
			return (0);
		i++;
	}
	return (res * sign);
}

int	erint(char *argv)
{
	if (toint(argv) <= 0 || toint(argv) > 2147483647)
		return (-1);
	return (0);
}
