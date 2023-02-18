/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:22 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/15 14:09:41 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bring_to_top(t_list **stack_a, int index)
{
	int	nodes;

	nodes = ft_count_nodes(*stack_a);
	if (index <= (nodes / 2))
		while (index--)
			ft_ra(stack_a, 1);
	else
		while (index++ < nodes)
			ft_rra(stack_a, 1);
}

void	ft_stack_size_2(t_list	**stack_a)
{
	if (!*stack_a || !stack_a)
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_sa(stack_a, 1);
}

void	ft_stack_size_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (!*stack_a || !stack_a)
		return ;
	if (first > second && third > first)
		ft_sa(stack_a, 1);
	else if (first > second && second > third)
	{
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (third > second && first > third)
		ft_ra(stack_a, 1);
	else if (third > first && second > third)
	{
		ft_sa(stack_a, 1);
		ft_ra(stack_a, 1);
	}
	else if (first > third && second > first)
		ft_rra(stack_a, 1);
}

void	ft_stack_size_4(t_list **stack_a, t_list **stack_b)
{
	int		count;
	t_list	*tmp;

	tmp = (*stack_a);
	count = ft_smallest(*stack_a, 0);
	ft_bring_to_top(stack_a, count);
	ft_pb(stack_a, stack_b);
	ft_stack_size_3(stack_a);
	ft_pa(stack_b, stack_a);
}

void	ft_stack_size_5(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = ft_smallest(*stack_a, 0);
	ft_bring_to_top(stack_a, count);
	ft_pb(stack_a, stack_b);
	count = ft_smallest(*stack_a, 1);
	ft_bring_to_top(stack_a, count);
	ft_pb(stack_a, stack_b);
	ft_stack_size_3(stack_a);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
}
