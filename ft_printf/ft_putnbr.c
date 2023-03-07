/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:46:15 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 09:55:56 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int result)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, result);
		result += ft_putchar('8');
	}
	else if (nb < 0)
	{
		result += ft_putchar('-');
		nb = nb * (-1);
		ft_putnbr(nb, result);
	}
	else if (nb <= 9)
		result += ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, result);
		ft_putnbr(nb % 10, result);
	}
	return (result);
}
