/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:32:20 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/13 17:14:39 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, int i)
{
	t_list	*tmp;
	t_list	*before_last;
	t_list	*last;

	if (!*stack_a || !stack_a)
		return ;
	tmp = (*stack_a);
	before_last = (*stack_a);
	last = ft_lstlast(*stack_a);
	while (before_last->next->next)
		before_last = before_last->next;
	last->next = tmp;
	before_last->next = NULL;
	(*stack_a) = last;
	if (i == 1)
		ft_putstr("\e[1m\e[35mrra\n");
}

void	ft_rrb(t_list **stack_b, int i)
{
	t_list	*tmp;
	t_list	*before_last;
	t_list	*last;

	if (!*stack_b || !stack_b)
		return ;
	tmp = (*stack_b);
	before_last = (*stack_b);
	last = ft_lstlast(*stack_b);
	while (before_last->next->next)
		before_last = before_last->next;
	last->next = tmp;
	before_last->next = NULL;
	(*stack_b) = last;
	if (i == 1)
		ft_putstr("\e[1m\e[35mrrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	ft_putstr("\e[1m\e[35mrrr\n");
}
// variable expand node