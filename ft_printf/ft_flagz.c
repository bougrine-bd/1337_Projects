/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:40:46 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 11:22:09 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flagz	ft_initia(void)
{
	t_flagz initi;

	initi.zero.type = NULL;
	initi.zero.value = 0;
	initi.minus.type = NULL;
	initi.minus.value = 0;
	initi.dot.type = NULL;
	initi.dot.value = -1;
	return (initi);
}

int		ft_zero(char *str, t_flagz *flag, va_list ap)
{
	int plus;
	int arg;

	plus = 0;
	while (*str == '0')
	{
		str++;
		plus++;
	}
	Z_TYP = "0";
	if (*str == '*')
	{
		arg = va_arg(ap, int);
		arg_gorl0(flag, arg);
		plus++;
		str++;
	}
	else
		Z_VAL = ft_atoi(str);
	if (ft_isdigit(*str) == 1)
		plus += ft_nblen(Z_VAL);
	return (plus);
}

int		ft_dot(char *str, t_flagz *flag, va_list ap)
{
	int plus;

	plus = 0;
	str++;
	plus++;
	if (*str == '*')
	{
		D_VAL = va_arg(ap, int);
		if (D_VAL > 0)
			D_TYP = ".";
		plus++;
		str++;
	}
	else
	{
		D_VAL = ft_atoi(str);
		D_TYP = ".";
	}
	if (ft_isdigit(*str) == 1)
		plus += ft_nblen(D_VAL);
	return (plus);
}

int		ft_minus(char *str, t_flagz *flag, va_list ap)
{
	int plus;

	plus = 0;
	while (*str == '-')
	{
		str++;
		plus++;
	}
	M_TYP = "-";
	if (*str == '*')
	{
		M_VAL = abss(va_arg(ap, int));
		plus++;
		str++;
	}
	else
		M_VAL = ft_atoi(str);
	if (ft_isdigit(*str) == 1)
		plus += ft_nblen(M_VAL);
	return (plus);
}

int		ft_width(char *str, t_flagz *flag, va_list ap)
{
	int plus;
	int arg;

	plus = 0;
	D_TYP = ".";
	if (*str == '*')
	{
		arg = va_arg(ap, int);
		arg_gorl0(flag, arg);
		plus++;
		str++;
	}
	else
		Z_VAL = ft_atoi(str);
	if (ft_isdigit(*str) == 1)
		plus += ft_nblen(Z_VAL);
	return (plus);
}
