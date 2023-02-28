/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:52:50 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/27 21:40:15 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a, int i)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*stack_a || !stack_a || !(*stack_a)->next)
		return ;
	tmp1 = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp2 = ft_lstlast(*stack_a);
	tmp2->next = tmp1;
	tmp1->next = NULL;
	if (i == 1)
		ft_putstr("ra\n");
}

void	ft_rb(t_list **stack_b, int i)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*stack_b || !stack_b || !(*stack_b)->next)
		return ;
	tmp1 = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp2 = ft_lstlast(*stack_b);
	tmp2->next = tmp1;
	tmp1->next = NULL;
	if (i == 1)
		ft_putstr("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int i)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (i == 1)
		ft_putstr("rr\n");
}
