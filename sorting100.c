/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:04:43 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/27 21:40:05 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunk(t_list **stack_a, t_list **stack_b, int start, int end)
{
	int		count;
	int		average;

	count = 0;
	average = (end + start - 1) / 2;
	while (count <= (end - start - 1) && ft_count_nodes(*stack_a))
	{
		if ((*stack_a)->rank >= start && (*stack_a)->rank < end)
		{
			ft_pb(stack_a, stack_b, 1);
			if ((*stack_a) && ((*stack_b)->rank > average)
				&& ((*stack_a)->rank >= end))
				ft_rr(stack_a, stack_b, 1);
			else if ((*stack_b)->rank > average)
				ft_rb(stack_b, 1);
			count++;
		}
		else
			ft_ra(stack_a, 1);
	}
}

void	ft_push_back_to_stack_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*max;
	t_list	*sec;

	while (ft_count_nodes(*stack_b))
	{
		max = ft_find_first_max(stack_b);
		sec = ft_find_second_max(stack_b);
		if (ft_count_nodes(*stack_b) == 1)
			ft_push_to_a(stack_b, stack_a, max->rank);
		else if (max->moves < sec->moves)
			ft_push_to_a(stack_b, stack_a, max->rank);
		else if (max->moves >= sec->moves)
		{
			ft_push_to_a(stack_b, stack_a, sec->rank);
			ft_push_to_a(stack_b, stack_a, max->rank);
			if ((*stack_a)->rank > (*stack_a)->next->rank)
				ft_sa(stack_a, 1);
		}
	}
}

void	ft_push_to_a(t_list **stack_b, t_list **stack_a, int rank)
{
	int		i;
	int		nodes;
	int		middle;
	t_list	*tmp;

	i = 0;
	nodes = ft_count_nodes(*stack_b) - 1;
	middle = nodes / 2;
	tmp = (*stack_b);
	ft_reindexing(stack_b);
	ft_moves(stack_b);
	while (i++ <= nodes && tmp->rank != rank)
		tmp = tmp->next;
	if (tmp->index <= middle)
		while (tmp->moves--)
			ft_rb(stack_b, 1);
	else
		while (tmp->moves--)
			ft_rrb(stack_b, 1);
	ft_pa(stack_b, stack_a, 1);
	ft_reindexing(stack_b);
	ft_moves(stack_b);
}

void	ft_stack_size_100(t_list **stack_a, t_list **stack_b)
{
	int	end;
	int	len;
	int	diff;
	int	start;

	start = 0;
	len = ft_count_nodes(*stack_a);
	end = len / 5;
	diff = len / 5;
	while (ft_count_nodes(*stack_a))
	{
		ft_push_chunk(stack_a, stack_b, start, end);
		start += diff;
		end += diff;
	}
	ft_reindexing(stack_b);
	ft_moves(stack_b);
	ft_push_back_to_stack_a(stack_b, stack_a);
}
