/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:18:31 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/01 17:59:56 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			num;
	long			data;
	struct s_stack	*next;
}t_stack;

void	add_element(t_stack **node, long data);
void	zerotomax(t_stack **stka);
void	sort3(t_stack **stka);
void	make_it3(t_stack **stka, t_stack **stkb, int min, int max);
void	returnsort(t_stack **stka, t_stack **stkb);
void	free_list(t_stack **list, int i);
void	errors(char *str, t_stack *stka);
long	toint(char *str, t_stack *stka);
void	c_doubles(t_stack *stka, int i);
int		in_stkb(t_stack *stkb, int num);
void	pos(t_stack **stka);
int		positioning(t_stack *stkb, int num);
int		issorted(t_stack *list);
int		minstack(t_stack *stka);
int		countstk(t_stack *list);
int		lastnum(t_stack *stka);
void	lastnig(t_stack **stka);
void	rrr(t_stack **stka, t_stack **stkb, int i);
void	rrab(t_stack **list, int i);
void	rr(t_stack **stka, t_stack **stkb, int i);
void	rab(t_stack **list, int i);
void	pushab(t_stack **from, t_stack **to, int i);
void	sab(t_stack *list, int i);
void	ss(t_stack *stka, t_stack *stkb, int i);

#endif