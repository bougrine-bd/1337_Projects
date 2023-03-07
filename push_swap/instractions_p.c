/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:08:04 by abougrin          #+#    #+#             */
/*   Updated: 2021/06/26 14:25:03 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrab(t_stack **list, int i)
{
	t_stack	*temp;
	t_stack	*start;

	if (!(*list) || !((*list)->next))
		return ;
	start = *list;
	temp = *list;
	while ((*list)->next)
		*list = (*list)->next;
	while (temp->next->next)
		temp = temp->next;
	(*list)->next = start;
	temp->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
	else if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stka, t_stack **stkb, int i)
{
	if (*stka && countstk(*stka) > 1)
		rrab(stka, -1);
	if (*stkb && countstk(*stkb) > 1)
		rrab(stkb, -1);
	if (i == 0)
		write(1, "rrr\n", 4);
}
