/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:03:48 by abougrin          #+#    #+#             */
/*   Updated: 2021/06/17 09:58:23 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	issorted(t_stack *list)
{
	while (list->next)
	{
		if (list->num > list->next->num)
			return (-1);
		list = list->next;
	}
	return (0);
}

int	minstack(t_stack *stka)
{
	int	min;

	min = 2147483647;
	while (stka)
	{
		if (stka->num < min)
			min = stka->num;
		stka = stka->next;
	}
	return (min);
}

int	countstk(t_stack *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

int	lastnum(t_stack *stka)
{
	while (stka->next)
		stka = stka->next;
	return (stka->num);
}

void	lastnig(t_stack **stka)
{
	t_stack	*temp;

	temp = *stka;
	while (temp->next)
		temp = temp->next;
	temp->num = -1;
}
