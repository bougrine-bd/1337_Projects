/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:32:26 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 16:10:55 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int result;

	result = 0;
	while (str && str[result])
		result += ft_putchar(str[result]);
	return (result);
}

int	ft_rev_str(char *str)
{
	int i;
	int result;

	i = 0;
	while (str[i])
		i++;
	result = i;
	while (i--)
		ft_putchar(str[i]);
	return (result);
}
