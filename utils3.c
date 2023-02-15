/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:00:28 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/15 12:34:01 by moudrib          ###   ########.fr       */
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
	int		count;
	int		smallest;

	count = 0;
	tmp = stack_a;
	while (tmp->rank != rank)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
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
