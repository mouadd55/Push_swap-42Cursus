/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:35:06 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/11 19:32:42 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->data = data;
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

void	insert_at_end(t_list **head, t_list *new)
{
	t_list	*end;

	if (!*head || !head)
		*head = new;
	else
	{
		end = ft_lstlast(*head);
		end->next = new;
	}
}

void	*destroy_list(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (!head || !*head || !tmp)
		return (0);
	while (tmp)
	{
		tmp = (*head)->next;
		free (*head);
		(*head) = tmp;
	}
	return (0);
}

// int	count_nodes(t_list *head)
// {
// 	t_list	*tmp;
// 	int count;

// 	count = 0;
// 	tmp = head;
// 	while (tmp)
// 	{
// 		count++;
// 		tmp = tmp->next;
// 	}
// 	return (count);
// }