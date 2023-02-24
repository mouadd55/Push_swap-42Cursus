/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:52:44 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/24 19:49:06 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves(t_list **stack)
{
	int		len;
	int		middle;
	t_list	*tmp;

	if (!*stack || !stack)
		return ;
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

t_list	*ft_find_first_max(t_list **stack_b)
{
	int		i;
	int		len;
	t_list	*tmp;

	i = 0;
	len = ft_count_nodes(*stack_b) - 1;
	tmp = (*stack_b);
	while (i++ <= len && tmp->rank != len)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_find_second_max(t_list **stack_b)
{
	int		i;
	int		len;
	t_list	*tmp;

	i = 0;
	len = ft_count_nodes(*stack_b) - 1;
	tmp = (*stack_b);
	while (i++ < len && tmp->rank != len - 1)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stack_size_500(t_list **stack_a, t_list **stack_b)
{
	int	end;
	int	len;
	int	diff;
	int	start;

	start = 0;
	len = ft_count_nodes(*stack_a);
	end = len / 9;
	diff = len / 9;
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
