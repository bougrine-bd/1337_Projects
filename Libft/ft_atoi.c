/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:51:17 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 18:58:00 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || *str == 11 || *str == 12 || *str == 13 || *str == 10
			|| *str == 9)
		str++;
	if (*str == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res < 0 && sign > 0)
			return (-1);
		if (res < 0 && sign < 0)
			return (0);
		str++;
	}
	return (res * sign);
}
