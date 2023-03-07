/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:49:24 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 15:34:46 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_all(char *str, t_flagz *flag, va_list ap, int result)
{
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*str), 1);
			result++;
			str++;
		}
		else if (*str++ == '%')
		{
			result += ft_check_flag(&str, flag, ap);
			result += ft_check_conv(&str, flag, ap);
			str++;
		}
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flagz flag;
	char	*str;
	int		result;

	flag = ft_initia();
	str = (char *)format;
	result = 0;
	va_start(ap, format);
	result += do_all(str, &flag, ap, 0);
	va_end(ap);
	return (result);
}
