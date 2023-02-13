/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/13 19:55:31 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft(t_list *stack, char c)
{
	t_list	*tmp;

	tmp = stack;
	printf("               \e[1m\e[93mStack %c      ", c);
	printf("\n-------------------------------------\n");
	printf("|   index    |   data    |   rank   |\n");
	printf("-------------------------------------\n");
	while (tmp)
	{
		printf("|%11d|%11d|%11d|\n", tmp->index, tmp->data, tmp->rank);
		tmp = tmp->next;
	}
	printf("-------------------------------------\n\n");
	ft_putstr("\x1B[0m");
}

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
	//ft_stack_size_3(&stack_a);
	ft(stack_a, 'A');
	ft(stack_b, 'B');
	system ("leaks push_swap");
	return (0);
}
