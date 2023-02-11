/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:44 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/11 19:33:44 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **stack_a, t_list **stack_b)
{
	ft_putstr("\x1B[31mError\x1B[0m");
	ft_putchar('\n');
	destroy_list(stack_a);
	destroy_list(stack_b);
	exit(0);
}

void	first_check(char **av, t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			ft_error(stack_a, stack_b);
		else if (count_words(av[i], ' ') == 0)
			ft_error(stack_a, stack_b);
		arr = ft_split(av[i], ' ');
		j = 0;
		while (arr[j])
		{
			if (ft_isdigit(arr[j]))
				insert_at_end(stack_a, create_node(ft_atoi(arr[j])));
			else
				ft_error(stack_a, stack_b);
			j++;
		}
		i++;
		free_arr(arr);
	}
}

int	check_duplicates(t_list *head)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		count;

	tmp1 = head;
	tmp2 = head;
	count = 0;
	while (tmp1)
	{
		tmp2 = head;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
				count++;
			if (count > 1)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		count = 0;
	}
	return (0);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	destroy_list(stack_a);
	return (1);
}
