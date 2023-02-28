/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:35:51 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/28 01:36:59 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a, int i)
{
	int	tmp1;
	int	tmp2;

	if (!*stack_a || !stack_a || !(*stack_a)->next)
		return ;
	tmp1 = (*stack_a)->data;
	tmp2 = (*stack_a)->rank;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->rank = (*stack_a)->next->rank;
	(*stack_a)->next->data = tmp1;
	(*stack_a)->next->rank = tmp2;
	if (i == 1)
		ft_putstr("sa\n");
}

void	ft_sb(t_list **stack_b, int i)
{
	int	tmp1;
	int	tmp2;

	if (!*stack_b || !stack_b || !(*stack_b)->next)
		return ;
	tmp1 = (*stack_b)->data;
	tmp2 = (*stack_b)->rank;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->rank = (*stack_b)->next->rank;
	(*stack_b)->next->data = tmp1;
	(*stack_b)->next->rank = tmp2;
	if (i == 1)
		ft_putstr("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b, int i)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (i == 1)
		ft_putstr("ss\n");
}
