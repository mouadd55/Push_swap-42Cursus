/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:00:28 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/19 16:40:01 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_nodes(t_list *head)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = head;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	ft_smallest(t_list *stack_a, int rank)
{
	t_list	*tmp;
	int		index;
	int		smallest;

	index = 0;
	if (!stack_a)
		return (0);
	tmp = stack_a;
	while (tmp && tmp->rank != rank)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	ft_index_util(t_list *stack_a)
{
	t_list	*tmp;
	int		index;
	int		count;
	int		smallest;

	index = 0;
	tmp = stack_a;
	smallest = INT_MAX;
	while (tmp)
	{
		if (tmp->rank == -1)
		{
			if (smallest > tmp->data)
			{
				smallest = tmp->data;
				index = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	return (index);
}

void	ft_stack_size(t_list **stack_a, t_list **stack_b)
{
	int	nodes;

	nodes = ft_count_nodes(*stack_a);
	if (nodes == 2)
		ft_stack_size_2(stack_a);
	else if (nodes == 3)
		ft_stack_size_3(stack_a);
	else if (nodes == 4)
		ft_stack_size_4(stack_a, stack_b);
	else if (nodes == 5)
		ft_stack_size_5(stack_a, stack_b);
	else if (nodes > 5 && nodes <= 100)
		ft_stack_size_100(stack_a, stack_b);
}

void	ft_reindexing(t_list **stack_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}
