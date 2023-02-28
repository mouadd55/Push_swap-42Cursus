/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:46:42 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/28 17:12:09 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_b, t_list **stack_a, int i)
{
	t_list	*tmp;

	if (!*stack_b || !stack_b)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	if (i == 1)
		ft_putstr("pa\n");
}

void	ft_pb(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*tmp;

	if (!*stack_a || !stack_a)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	if (i == 1)
		ft_putstr("pb\n");
}
