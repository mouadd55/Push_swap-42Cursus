/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/12 00:06:36 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft(t_list *list, char c)
{
	t_list	*node;

	node = list;
	printf("               Stack %c      ", c);
	printf("\n-------------------------------------\n");
	printf("|   node    |   data    |   index   |\n");
	printf("-------------------------------------\n");
	while (node)
	{
		printf("|%11d|%11d|%11d|\n", 0, node->data, 0);
		node = node->next;
	}
	printf("-------------------------------------\n\n");
}

int	int_limits(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		first_check(av, &stack_a, &stack_b);
		if (int_limits(av))
			ft_error(&stack_a, &stack_b);
		else if (check_duplicates(stack_a))
			ft_error(&stack_a, &stack_b);
		else if (is_sorted(&stack_a))
			return (0);
	}
	ft(stack_a, 'A');
	ft(stack_b, 'B');
	system ("leaks push_swap");
	return (0);
}
