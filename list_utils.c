/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:35:06 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/27 13:48:18 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data, int index, int rank)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->data = data;
	head->index = index;
	head->rank = rank;
	head->next = NULL;
	return (head);
}

t_list	*ft_lstlast(t_list *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head -> next == NULL)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tmp;

	if (!*head || !head)
		*head = new;
	else
	{
		tmp = ft_lstlast(*head);
		tmp->next = new;
	}
}

void	*ft_destroy_list(t_list **head)
{
	t_list	*tmp;

	if (!head || !*head)
		return (0);
	tmp = *head;
	while (tmp)
	{
		tmp = (*head)->next;
		free (*head);
		(*head) = tmp;
	}
	return (0);
}

void	ft_sort_rank(t_list *stack_a)
{
	int		i;
	t_list	*tmp;
	int		rank;
	int		nodes;
	int		smallest;

	i = 0;
	rank = 0;
	tmp = stack_a;
	nodes = ft_count_nodes(stack_a);
	while (rank < nodes)
	{
		smallest = ft_index_util(stack_a);
		while (i++ < smallest)
			tmp = tmp->next;
		if (tmp->rank == -1)
			tmp->rank = rank;
		i = 0;
		rank++;
		tmp = stack_a;
	}
}
