/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:22:22 by abougrin          #+#    #+#             */
/*   Updated: 2019/10/28 21:28:07 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !(*lst) || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp;
		del(tmp->content);
		tmp = tmp->next;
		free(tmp2);
	}
	*lst = NULL;
}
