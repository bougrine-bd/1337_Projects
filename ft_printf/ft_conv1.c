/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:33:20 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 12:58:42 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_s(t_flagz *flag, va_list ap, int result)
{
	char	*arg;
	int		lenarg;
	int		larger;

	arg = va_arg(ap, char*);
	lenarg = arg ? ft_strlen(arg) : putnull("(null)", &arg);
	larger = D_TYP && D_VAL > -1 ? D_VAL : lenarg;
	if (D_VAL > lenarg)
		larger = lenarg;
	if (M_TYP)
		result += ft_help_s(flag, arg);
	else
	{
		result += extraline_z(flag, larger);
		nbofchar(&arg, D_VAL, flag);
		result += D_VAL == 0 ? 0 : ft_putstr(arg);
	}
	*flag = ft_initia();
	return (result);
}

int	ft_percent(t_flagz *flag)
{
	int result;

	result = 0;
	if (M_TYP)
	{
		result += ft_putchar('%');
		while (M_VAL > 1)
		{
			result += ft_putchar(' ');
			M_VAL--;
		}
	}
	else
	{
		result += ft_help_percent(flag);
		result += ft_putchar('%');
	}
	*flag = ft_initia();
	return (result);
}
