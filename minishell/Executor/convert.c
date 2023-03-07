/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moukasso <moukasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:09:49 by moukasso          #+#    #+#             */
/*   Updated: 2021/10/26 09:10:45 by moukasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

extern t_data	g_data;

int	ft_atoi(char *str, int *err)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	str += skip_spaces(str);
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - 48);
		if (result > INT_MAX || ((result * sign) < INT_MIN))
			break ;
		str++;
	}
	str += skip_spaces(str);
	if (*str)
	{
		*err = 1;
		return (0);
	}
	return (result * sign);
}

char	*ft_itoa(int num)
{
	int		nb_of_digits;
	char	*num_str;

	nb_of_digits = number_of_digits(num);
	num_str = malloc(nb_of_digits + 1);
	if (!num_str)
		return (NULL);
	num_str[nb_of_digits] = '\0';
	while (--nb_of_digits)
	{
		num_str[nb_of_digits] = (num % 10) + 48;
		num /= 10;
	}
	num_str[nb_of_digits] = (num % 10) + 48;
	return (num_str);
}

int	number_of_digits(int num)
{
	int	counter;

	counter = 1;
	while (num >= 10)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}
