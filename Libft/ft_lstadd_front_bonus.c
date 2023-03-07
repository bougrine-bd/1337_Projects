/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:38:46 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 21:48:48 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!alst || !new)
		return ;
	tmp = new;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *alst;
	*alst = new;
}
