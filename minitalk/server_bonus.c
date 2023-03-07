/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:42:33 by abougrin          #+#    #+#             */
/*   Updated: 2021/06/23 09:27:24 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	handler(int sig_num)
{
	static int	bit;
	static char	c;

	if (sig_num == SIGUSR1)
		sigaddset(&c, ++bit);
	else
		bit++;
	if (bit == 8)
	{
		if (c)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		c = 0;
		bit = 0;
	}
}

char	*join_str(char *str, char c)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	temp = malloc(i + 2);
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	temp[j] = c;
	temp[j + 1] = '\0';
	free(str);
	return (temp);
}

void	putnum(int num)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(1);
	str[0] = '\0';
	while (num != 0)
	{
		if ((num % 10) < 10)
			str = join_str(str, (num % 10) + '0');
		num /= 10;
	}
	while (str[i])
		i++;
	while (i--)
		write(1, &str[i], 1);
	free(str);
	write(1, "\n", 1);
}

int	main (void)
{	
	int	pid;

	pid = getpid();
	putnum(pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
