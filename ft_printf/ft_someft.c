/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_someft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:39:58 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 09:49:42 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	abss(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	printzero(int value, int nbr)
{
	int result;

	result = 0;
	while (value > nbr)
	{
		result += ft_putchar('0');
		value--;
	}
	return (result);
}

int	arg_gorl0(t_flagz *flag, int arg)
{
	if (arg >= 0)
		Z_VAL = arg;
	else
	{
		M_TYP = "-";
		M_VAL = abss(arg);
	}
	return (0);
}

int	ft_dec_to_hex(size_t num, char str)
{
	char	buff[17];
	int		mod;
	size_t	i;

	mod = 0;
	i = 0;
	if (num == 0)
		buff[i++] = '0';
	while (num > 0)
	{
		mod = num % 16;
		if (mod < 10)
		{
			buff[i] = mod + 48;
			i++;
		}
		else
		{
			buff[i] = mod + ((str == 'x' || str == 'p') ? 87 : 55);
			i++;
		}
		num = num / 16;
	}
	buff[i] = '\0';
	return (ft_rev_str(buff));
}

int	lenhex(size_t num, char str)
{
	char	buff[17];
	int		mod;
	size_t	i;

	mod = 0;
	i = 0;
	if (num == 0)
		buff[i++] = '0';
	while (num > 0)
	{
		mod = num % 16;
		if (mod < 10)
		{
			buff[i] = mod + 48;
			i++;
		}
		else
		{
			buff[i] = mod + ((str == 'x' || str == 'p') ? 87 : 55);
			i++;
		}
		num = num / 16;
	}
	buff[i] = '\0';
	return (ft_strlen(buff));
}
