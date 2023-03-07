/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:57:32 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 11:24:53 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flag(char **str, t_flagz *flag, va_list ap)
{
	if (**str == '0')
		*str += ft_zero(*str, flag, ap);
	if (**str == '-')
		*str += ft_minus(*str, flag, ap);
	if (**str == '*' || ft_isdigit(**str) == 1)
		*str += ft_width(*str, flag, ap);
	if (**str == '.')
		*str += ft_dot(*str, flag, ap);
	return (0);
}

int	ft_check_conv(char **str, t_flagz *flag, va_list ap)
{
	if (**str == '%')
		return (ft_percent(flag));
	if (**str == 'c')
		return (ft_conv_c(flag, ap));
	else if (**str == 'd' || **str == 'i')
		return (ft_conv_d(flag, ap));
	else if (**str == 'u')
		return (ft_conv_u(flag, ap));
	else if (**str == 'x' || **str == 'X')
		return (ft_conv_x(str, flag, ap));
	else if (**str == 's')
		return (ft_conv_s(flag, ap, 0));
	else if (**str == 'p')
		return (ft_conv_p(str, flag, ap));
	return (0);
}
