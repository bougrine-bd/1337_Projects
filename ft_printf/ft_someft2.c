/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_someft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:18:56 by abougrin          #+#    #+#             */
/*   Updated: 2019/12/30 12:23:16 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnull(char *null, char **arg)
{
	*arg = null;
	return (6);
}

int	nbofchar(char **str, int nb, t_flagz *flag)
{
	char	*dest;
	int		result;
	int		i;

	dest = malloc(nb + 1);
	result = D_VAL != -1 ? nb : 0;
	i = 0;
	if (nb > 0)
	{
		while (nb > 0)
		{
			dest[i] = str[0][i];
			i++;
			nb--;
		}
		dest[i] = '\0';
		*str = dest;
	}
	free(dest);
	return (result);
}

int	extraline_z(t_flagz *flag, int larger)
{
	int result;

	result = 0;
	while (D_TYP && Z_VAL > larger)
	{
		result += ft_putchar(' ');
		Z_VAL--;
	}
	return (result);
}

int	extraline_m(t_flagz *flag, int lenarg)
{
	int result;

	result = 0;
	while (M_VAL - lenarg > 0)
	{
		result += ft_putchar(' ');
		M_VAL--;
	}
	return (result);
}
