/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:22 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/13 17:50:56 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
		ft_rra(stack_a, 1);
}

// void	ft_stack_size_4(t_list **stack_a)
// {
// 	int	
// }