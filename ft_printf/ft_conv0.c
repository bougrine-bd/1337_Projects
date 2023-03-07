/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:51:44 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 11:50:03 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c(t_flagz *flag, va_list ap)
{
	int result;
	int arg;

	result = 0;
	arg = va_arg(ap, int);
	if (M_VAL)
	{
		result += ft_putchar(arg);
		while (M_VAL - 1 > 0)
		{
			result += ft_putchar(' ');
			M_VAL--;
		}
	}
	else
	{
		while (D_TYP && Z_VAL - 1 > 0)
		{
			result += ft_putchar(' ');
			Z_VAL--;
		}
		result += ft_putchar(arg);
	}
	*flag = ft_initia();
	return (result);
}

int	ft_conv_d(t_flagz *flag, va_list ap)
{
	int result;
	int arg;
	int lenarg;
	int larger;

	result = 0;
	arg = va_arg(ap, int);
	lenarg = ft_nblen(arg);
	larger = (D_VAL > lenarg) ? D_VAL : lenarg;
	arg < 0 ? larger++ : 0;
	arg == 0 && D_VAL == 0 ? larger-- : 0;
	if (M_TYP)
		result += ft_help_d(flag, arg);
	else
	{
		result += extraline_z(flag, larger);
		arg < 0 ? result += ft_putchar('-') : 0;
		(arg < 0) && D_TYP == NULL ? lenarg++ : 0;
		result += D_TYP ? printzero(D_VAL, lenarg) : printzero(Z_VAL, lenarg);
		result += arg == 0 && D_VAL == 0 ? 0 : ft_putstr(ft_itoa(abss(arg)));
	}
	*flag = ft_initia();
	return (result);
}

int	ft_conv_u(t_flagz *flag, va_list ap)
{
	int				result;
	unsigned int	arg;
	int				lenarg;
	int				larger;

	result = 0;
	arg = va_arg(ap, unsigned int);
	lenarg = ft_nblen(arg);
	larger = (D_VAL > lenarg) ? D_VAL : lenarg;
	arg == 0 && D_VAL == 0 ? larger-- : 0;
	if (M_TYP)
		result += ft_help_u(flag, arg);
	else
	{
		result += extraline_z(flag, larger);
		result += D_TYP ? printzero(D_VAL, lenarg) : printzero(Z_VAL, lenarg);
		result += arg == 0 && D_VAL == 0 ? 0 : ft_putstr(ft_itoa(arg));
	}
	*flag = ft_initia();
	return (result);
}

int	ft_conv_x(char **str, t_flagz *flag, va_list ap)
{
	int				result;
	unsigned int	arg;
	int				lenarg;
	int				larger;

	result = 0;
	arg = va_arg(ap, unsigned int);
	lenarg = lenhex(arg, **str);
	larger = (D_VAL > lenarg) ? D_VAL : lenarg;
	arg == 0 && D_VAL == 0 ? larger-- : 0;
	if (M_TYP)
		result += ft_help_x(str, flag, arg);
	else
	{
		result += extraline_z(flag, larger);
		result += D_TYP ? printzero(D_VAL, lenarg) : printzero(Z_VAL, lenarg);
		result += arg == 0 && D_VAL == 0 ? 0 : ft_dec_to_hex(arg, **str);
	}
	*flag = ft_initia();
	return (result);
}

int	ft_conv_p(char **str, t_flagz *flag, va_list ap)
{
	int		result;
	size_t	arg;
	int		lenarg;

	result = 0;
	arg = va_arg(ap, size_t);
	lenarg = lenhex(arg, **str) + 2;
	arg == 0 && D_VAL == 0 ? lenarg-- : 0;
	if (M_TYP)
	{
		write(1, "0x", 2);
		result += arg == 0 && D_VAL == 0 ? 2 : ft_dec_to_hex(arg, **str) + 2;
		result += extraline_m(flag, lenarg);
	}
	else
	{
		result += extraline_z(flag, lenarg);
		write(1, "0x", 2);
		result += arg == 0 && D_VAL == 0 ? 2 : ft_dec_to_hex(arg, **str) + 2;
	}
	*flag = ft_initia();
	return (result);
}
