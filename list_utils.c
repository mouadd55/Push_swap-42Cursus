/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:35:06 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/08 14:27:23 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_list	*create_node(int data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	head->previous = NULL;
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
