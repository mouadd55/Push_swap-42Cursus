/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:04:43 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/21 22:44:34 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves(t_list **stack)
{
	int		len;
	int		middle;
	t_list	*tmp;

	tmp = (*stack);
	len = ft_count_nodes(*stack);
	middle = len / 2;
	while (tmp)
	{
		if (tmp->index <= middle)
			tmp->moves = tmp->index;
		else
			tmp->moves = len - tmp->index;
		tmp = tmp->next;
	}	
}

int	ft_organize_b(t_list **stack_b, int average)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (tmp->rank > average)
		return (1);
	return (0);
}

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
			ft_pb(stack_a, stack_b);
			if ((*stack_a) && ((*stack_b)->rank > average)
				&& ((*stack_a)->rank >= end))
				ft_rr(stack_a, stack_b);
			else if ((*stack_b)->rank > average)
				ft_rb(stack_b, 1);
			count++;
		}
		else
			ft_ra(stack_a, 1);
	}
}

void	ft_push_back_to_a(t_list **stack_b, t_list **stack_a, int len)
{
	int		nodes;
	int		middle;
	int		biggest;
	t_list	*tmp;

	nodes = len;
	while (--nodes >= 0)
	{
		middle = nodes / 2;
		tmp = (*stack_b);
		ft_reindexing(stack_b);
		ft_moves(stack_b);
		while (tmp->next && tmp->rank != nodes)
			tmp = tmp->next;
		biggest = ft_smallest(*stack_a, nodes);
		if (tmp->index <= middle)
			while (tmp->moves--)
				ft_rb(stack_b, 1);
		else
			while (tmp->moves--)
				ft_rrb(stack_b, 1);
		ft_pa(stack_b, stack_a);
	}
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
	ft_push_back_to_a(stack_b, stack_a, len);
}

// void	ft_push_chunk(t_list **stack_a, t_list **stack_b, int start, int end)
// {
// 	static int i = 0;
// 	int	count;
// 	int	average;
// 	int	middle;
// 	t_list	*tmp1;
// 	t_list	*tmp2;

// 	count = 0;
// 	middle = 0;
// 	average = (end + start - 1) / 2;
// 	tmp1 = (*stack_a);
// 	tmp2 = (*stack_a);
// 	while (tmp1->rank >= end && tmp1)
// 		tmp1 = tmp1->next;
// 	while (i < end && ft_count_nodes(*stack_a) && tmp2->next)
// 	{
// 		if (tmp2->rank >= start && tmp2->rank < end)
// 			i++;
// 		if (i < end)
// 			tmp2 = tmp2->next;
// 	}
// 	if (tmp1->moves >= tmp2->moves)
// 	{
// 		while (count <= (end - start - 1) && ft_count_nodes(*stack_a))
// 		{
// 			if ((*stack_a)->rank >= start && (*stack_a)->rank < end)
// 			{
// 				ft_pb(stack_a, stack_b);
// 				ft_organize_b(stack_b, average);
// 				count++;
// 			}
// 			else
// 				ft_ra(stack_a, 1);
// 		}
// 	}
// 	else
// 	{
// 		while (count <= (end - start - 1) && ft_count_nodes(*stack_a))
// 		{
// 			if ((*stack_a)->rank >= start && (*stack_a)->rank < end)
// 			{
// 				ft_pb(stack_a, stack_b);
// 				ft_organize_b(stack_b, average);
// 				count++;
// 			}
// 			else
// 				ft_rra(stack_a, 1);
// 		}
// 	}
// }

// void	ft_push_chunk(t_list **stack_a, t_list **stack_b, int start, int end)
// {
// 	int		middle;
// 	int		average;
// 	t_list	*tmp;

// 	average = (end + start - 1) / 2;
// 	while (start < end && ft_count_nodes(*stack_a))
// 	{
// 		middle = ft_count_nodes(*stack_a) / 2;
// 		tmp = (*stack_a);
// 		while (tmp->next && tmp->rank != start)
// 			tmp = tmp->next;
// 		if (tmp->index < middle)
// 			while (tmp->moves--)
// 				ft_ra(stack_a, 1);
// 		else
// 			while (tmp->moves--)
// 				ft_rra(stack_a, 1);
// 		ft_pb(stack_a, stack_b);
// 		ft_organize_b(stack_b, average);
// 		ft_reindexing(stack_a);
// 		ft_moves(stack_a);
// 		start++;
// 	}
// }