/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:59:11 by abougrin          #+#    #+#             */
/*   Updated: 2021/06/26 14:23:22 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sab(t_stack *list, int i)
{
	long	temp;

	if (!list || !(list->next))
		return ;
	temp = list->num;
	list->num = list->next->num;
	list->next->num = temp;
	if (i == 0)
		write(1, "sa\n", 3);
	else if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stka, t_stack *stkb, int i)
{
	if (stkb && countstk(stkb) > 1)
		sab(stkb, -1);
	if (stka && countstk(stka) > 1)
		sab(stka, -1);
	if (i == 0)
		write(1, "ss\n", 3);
}

void	pushab(t_stack **from, t_stack **to, int i)
{
	t_stack	*starta;

	if (!(*from) || countstk(*from) < 1)
		return ;
	starta = *from;
	*from = (*from)->next;
	starta->next = *to;
	*to = starta;
	if (i == 0)
		write(1, "pa\n", 3);
	else if (i == 1)
		write(1, "pb\n", 3);
}

void	rab(t_stack **list, int i)
{
	t_stack	*temp;
	t_stack	*start;

	if (!(*list) || !((*list)->next))
		return ;
	start = *list;
	temp = *list;
	*list = (*list)->next;
	while (temp->next)
		temp = temp->next;
	temp->next = start;
	start->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
	else if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stka, t_stack **stkb, int i)
{
	if (*stka && countstk(*stka) > 1)
		rab(stka, -1);
	if (*stkb && countstk(*stkb) > 1)
		rab(stkb, -1);
	if (i == 0)
		write(1, "rr\n", 3);
}
