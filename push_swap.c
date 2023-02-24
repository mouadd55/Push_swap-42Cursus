/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/24 19:35:36 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_first_check(av, &stack_a, &stack_b);
		if (ft_limits(av) || ft_duplicates(stack_a))
			ft_error(&stack_a, &stack_b);
		else if (ft_is_sorted(&stack_a))
			return (0);
	}
	ft_sort_index(stack_a);
	ft_moves(&stack_a);
	ft_stack_size(&stack_a, &stack_b);
	ft_destroy_list(&stack_a);
	ft_destroy_list(&stack_b);
	return (0);
}
