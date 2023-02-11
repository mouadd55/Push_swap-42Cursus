/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:35:51 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/12 00:09:26 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a, int i)
{
	int	tmp;

	if (!*stack_a || !stack_a)
		return ;
	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
	if (i == 1)
		write (1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b, int i)
{
	int	tmp;

	if (!*stack_b || !stack_b)
		return ;
	tmp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp;
	if (i == 1)
		write (1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	write (1, "ss\n", 3);
}
