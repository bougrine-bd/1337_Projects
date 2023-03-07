/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:08:52 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/01 17:55:35 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	append(t_stack **list, int *arr, int max)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *list;
	while (i < max)
	{
		(*list)->num = arr[i];
		(*list) = (*list)->next;
		i++;
	}
	*list = temp;
}

void	zerotomax(t_stack **stka)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		j;

	temp = *stka;
	while (temp)
	{
		temp->data = temp->num;
		temp = temp->next;
	}
	temp = *stka;
	while (temp)
	{
		j = 0;
		temp2 = *stka;
		while (temp2)
		{
			if (temp->num > temp2->data)
				j++;
			temp2 = temp2->next;
		}
		temp->num = j;
		temp = temp->next;
	}
}

void	sort3(t_stack **stka)
{
	t_stack	*p1;

	while (issorted(*stka) == -1)
	{
		p1 = *stka;
		if (p1->num < p1->next->num)
		{
			if (p1->num > p1->next->next->num)
				rrab(stka, 0);
			else
				sab(*stka, 0);
		}
		else if (p1->next->next && p1->num > p1->next->next->num)
			rab(stka, 0);
		else if (p1->next->next && p1->num < p1->next->next->num)
			sab(*stka, 0);
		else if (p1->num > p1->next->num)
			sab(*stka, 0);
	}
}

void	make_it3(t_stack **stka, t_stack **stkb, int min, int max)
{
	int	npush;
	int	x;

	while (countstk(*stka) > 3)
	{
		x = (countstk(*stka) - 3) / 2;
		if (countstk(*stka) > 400)
			x = (countstk(*stka) - 3) / 6;
		npush = x + 1;
		min = minstack(*stka);
		max = min + x;
		while (npush)
		{
			if ((*stka)->num > max)
				rab(stka, 0);
			else
			{
				pushab(stka, stkb, 1);
				if (countstk(*stkb) >= 2)
					if ((*stkb)->num < ((min + max) / 2))
						rab(stkb, 1);
				npush--;
			}
		}
	}
}

void	returnsort(t_stack **sa, t_stack **sb)
{
	while (*sb)
	{
		if (in_stkb(*sb, (*sa)->num - 1) == -1 && ((*sa)->num - 1) != -1)
			rrab(sa, 0);
		else
		{
			if ((*sb)->num == ((*sa)->num - 1))
				pushab(sb, sa, 0);
			else if ((*sb)->num < (*sa)->num && (*sb)->num > lastnum(*sa))
			{
				pushab(sb, sa, 0);
				rab(sa, 0);
			}
			else
			{
				if (positioning(*sb, (*sa)->num - 1) <= (countstk(*sb) / 2))
					rab(sb, 1);
				else
					rrab(sb, 1);
			}
		}
	}
}
