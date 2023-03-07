/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:07:28 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/01 17:43:46 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_list(t_stack **list, int i)
{
	t_stack	*temp;

	if (i == -1)
		write(1, "Error\n", 6);
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	exit(0);
}

void	errors(char *str, t_stack *stka)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			count++;
		else if (str[i] < '0' || str[i] > '9')
			free_list(&stka, -1);
		i++;
	}
	if (count > 1 || i > 11)
		free_list(&stka, -1);
}

long	toint(char *str, t_stack *stka)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	errors(str, stka);
	if (str[i] == '-')
		sign = -1;
	i += (str[0] == '-' || str[0] == '+');
	if (str[i] < '0' || str[i] > '9')
		free_list(&stka, -1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res < 0 && sign > 0)
			return (-1);
		if (res < 0 && sign < 0)
			return (0);
		i++;
	}
	return (res * sign);
}

void	c_doubles(t_stack *stka, int i)
{
	t_stack	*temp;
	t_stack	*sfree;

	sfree = stka;
	while (stka)
	{
		temp = stka->next;
		while (temp)
		{
			if (stka->num == temp->num)
				free_list(&sfree, -1);
			temp = temp->next;
		}
		if (stka->num < -2147483648 || stka->num > 2147483647)
			free_list(&sfree, -1);
		stka = stka->next;
	}	
	if (issorted(sfree) == 0 && i != 0)
		free_list(&sfree, 0);
}
