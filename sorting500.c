/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:52:44 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/21 22:43:51 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_size_500(t_list **stack_a, t_list **stack_b)
{
	int	end;
	int	len;
	int	diff;
	int	start;

	start = 0;
	len = ft_count_nodes(*stack_a);
	end = len / 11;
	diff = len / 11;
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
