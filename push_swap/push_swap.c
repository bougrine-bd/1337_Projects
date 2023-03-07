/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 09:30:12 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/01 17:49:23 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;
	int		i;

	stkb = NULL;
	stka = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
		add_element(&stka, toint(argv[i], stka));
	c_doubles(stka, 1);
	zerotomax(&stka);
	make_it3(&stka, &stkb, 0, 0);
	sort3(&stka);
	if (argc > 4)
	{
		lastnig(&stka);
		returnsort(&stka, &stkb);
		pos(&stka);
		while (issorted(stka) == -1)
			rrab(&stka, 0);
	}
	free_list(&stka, 0);
	return (0);
}
