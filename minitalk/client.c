/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:05:30 by abougrin          #+#    #+#             */
/*   Updated: 2021/06/23 09:54:12 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	send_sig(int num, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (num & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "ERORR : PID Not Exists\n", 23);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "ERORR : PID Not Exists\n", 23);
				exit(0);
			}
		}
		usleep(50);
		bit++;
	}
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || *str == 11 || *str == 12 || *str == 13 || *str == 10
		|| *str == 9)
		str++;
	if (*str == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res < 0 && sign > 0)
			return (-1);
		if (res < 0 && sign < 0)
			return (0);
		str++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write (1, "ERORR : Should be 3 Para!\n", 26);
		exit(0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_sig(av[2][i++], pid);
	send_sig(0, pid);
}
