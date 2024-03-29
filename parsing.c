/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:44 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/27 13:46:27 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **stack_a, t_list **stack_b)
{
	ft_putstr("\e[1m\x1B[31mError\x1B[0m");
	ft_putchar('\n');
	ft_destroy_list(stack_a);
	ft_destroy_list(stack_b);
	exit(0);
}

/*This function helps to detect is there any empty argument then
split each argument and check if it's a valid number using
ft_isdigit function after that i fill my linked list by adding the
converted strings to integers at the end of the list and adding an
index to each node from 0 (the first integer) until the last node.
For the -1 argument it helps me later to give the right rank to each node*/
void	ft_first_check(char **av, t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		index;
	char	**arr;

	i = 0;
	index = 0;
	while (av[++i])
	{
		if (ft_count_words(av[i], ' ') == 0)
			ft_error(stack_a, stack_b);
		arr = ft_split(av[i], ' ');
		j = -1;
		while (arr[++j])
		{
			if (ft_isdigit(arr[j]))
				ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(arr[j]), index, -1));
			else
				ft_error(stack_a, stack_b);
			index++;
		}
		ft_free_arr(arr);
	}
}

int	ft_limits(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			return (1);
	return (0);
}

int	ft_duplicates(t_list *head)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		count;

	tmp1 = head;
	while (tmp1)
	{
		count = 0;
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
	}
	return (0);
}

int	ft_is_sorted(t_list **stack_a)
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
	ft_destroy_list(stack_a);
	return (1);
}
