/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:00:11 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 12:25:12 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_help_d(t_flagz *flag, int arg)
{
	int result;
	int lenarg;
	int larger;

	result = 0;
	lenarg = ft_nblen(arg);
	larger = D_VAL > lenarg ? D_VAL : lenarg;
	arg < 0 ? larger++ : 0;
	arg < 0 ? result += ft_putchar('-') : 0;
	result += D_TYP ? printzero(D_VAL, lenarg) : 0;
	arg == 0 && D_VAL == 0 ? larger-- : 0;
	result += arg == 0 && D_VAL == 0 ? 0 : ft_putstr(ft_itoa(abss(arg)));
	while (M_VAL > larger)
	{
		result += ft_putchar(' ');
		M_VAL--;
	}
	return (result);
}

int	ft_help_u(t_flagz *flag, unsigned int arg)
{
	int result;
	int lenarg;
	int larger;

	result = 0;
	lenarg = ft_nblen(arg);
	larger = D_VAL > lenarg ? D_VAL : lenarg;
	result += D_TYP ? printzero(D_VAL, lenarg) : 0;
	arg == 0 && D_VAL == 0 ? larger-- : 0;
	result += arg == 0 && D_VAL == 0 ? 0 : ft_putstr(ft_itoa(arg));
	while (M_VAL > larger)
	{
		result += ft_putchar(' ');
		M_VAL--;
	}
	return (result);
}

int	ft_help_x(char **str, t_flagz *flag, unsigned int arg)
{
	int result;
	int lenarg;
	int larger;

	result = 0;
	lenarg = lenhex(arg, **str);
	larger = D_VAL > lenarg ? D_VAL : lenarg;
	result += D_TYP ? printzero(D_VAL, lenarg) : 0;
	arg == 0 && D_VAL == 0 ? larger-- : 0;
	result += arg == 0 && D_VAL == 0 ? 0 : ft_dec_to_hex(arg, **str);
	while (M_VAL > larger)
	{
		result += ft_putchar(' ');
		M_VAL--;
	}
	return (result);
}

int	ft_help_s(t_flagz *flag, char *arg)
{
	int result;
	int lenarg;
	int larger;

	result = 0;
	lenarg = arg ? ft_strlen(arg) : putnull("(null)", &arg);
	larger = D_TYP && D_VAL != -1 ? D_VAL : lenarg;
	if (D_VAL > lenarg || D_VAL < 0)
		larger = lenarg;
	nbofchar(&arg, D_VAL, flag);
	result += D_VAL == 0 ? 0 : ft_putstr(arg);
	while (M_VAL > larger)
	{
		result += ft_putchar(' ');
		M_VAL--;
	}
	return (result);
}

int	ft_help_percent(t_flagz *flag)
{
	int result;

	result = 0;
	if (Z_TYP)
		while (Z_VAL > 1)
		{
			result += ft_putchar('0');
			Z_VAL--;
		}
	else
		while (Z_VAL > 1)
		{
			result += ft_putchar(' ');
			Z_VAL--;
		}
	return (result);
}
