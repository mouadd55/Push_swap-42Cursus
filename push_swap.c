/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/07 18:23:18 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr("\x1B[31mError\x1B[0m");
	exit(0);
}

void	ft(t_list *list)
{
	t_list	*node;

	node = list;
	printf("----------------------------------\n");
	printf("|    node  |    data  |    index |\n");
	printf("----------------------------------\n");
	while (node)
	{
		printf("|%10d|%10d|%10d|\n", 0, node->data, 0);
		node = node->next;
	}
	printf("----------------------------------\n");
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

int	main(int ac, char **av)
{
	t_list	*head;

	head = NULL;
	if (ac >= 1)
		first_check(av, &head);
	ft(head);
	return (0);
}
