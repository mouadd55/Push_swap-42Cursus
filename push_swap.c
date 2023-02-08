/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/08 15:45:23 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft(t_list *list)
{
	t_list	*node;

	node = list;
	printf("-------------------------------------\n");
	printf("|   node    |   data    |   index   |\n");
	printf("-------------------------------------\n");
	while (node)
	{
		printf("|%11d|%11d|%11d|\n", 0, node->data, 0);
		node = node->next;
	}
	printf("-------------------------------------\n");
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
	t_list	*head;

	head = NULL;
	if (ac > 1)
	{
		first_check(av, &head);
		if (int_limits(av))
			ft_error();
		else if (check_duplicates(head))
			ft_error();
		else if (is_sorted(head))
			return (0);
	}
	ft(head);
	return (0);
}

