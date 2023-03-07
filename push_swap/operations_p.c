/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:06:38 by abougrin          #+#    #+#             */
/*   Updated: 2021/06/17 09:56:58 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_element(t_stack **node, long data)
{
	t_stack	*element;
	t_stack	*temp;

	temp = *node;
	element = malloc(sizeof(t_stack));
	element->num = data;
	element->next = NULL;
	if (*node == NULL)
	{
		*node = element;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = element;
}

int	in_stkb(t_stack *stkb, int num)
{
	while (stkb)
	{
		if (stkb->num == num)
			return (0);
		stkb = stkb->next;
	}
	return (-1);
}

void	pos(t_stack **stka)
{
	t_stack	*temp;
	int		num;

	num = 0;
	temp = *stka;
	while (temp->num != -1)
	{
		num = temp->num;
		temp = temp->next;
	}
	temp->num = num + 1;
}

int	positioning(t_stack *stkb, int num)
{
	int	i;

	i = 0;
	while (stkb)
	{
		if (stkb->num == num)
			return (i);
		i++;
		stkb = stkb->next;
	}
	return (-1);
}
