/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:44 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/08 14:27:19 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_error(void)
{
	ft_putstr("\x1B[31mError\x1B[0m");
	exit(0);
}

void	first_check(char **av, t_list **head)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			ft_error();
		else if (count_words(av[i], ' ') == 0)
			ft_error();
		arr = ft_split(av[i], ' ');
		j = 0;
		while (arr[j])
		{
			if (ft_isdigit(arr[j]))
				insert_at_end(head, create_node(ft_atoi(arr[j])));
			else
				ft_error();
			j++;
		}
		i++;
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

int	is_sorted(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
