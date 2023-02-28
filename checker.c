/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:32:48 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/28 20:48:55 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_execute_instructions(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(stack_a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(stack_b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(stack_b, stack_a, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(stack_a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(stack_b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(stack_a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(stack_b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(stack_a, stack_a, 0);
	else
		ft_error(stack_a, stack_b);
}

void	read_from_stdin(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_execute_instructions(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	if ((*stack_a) && ft_is_sorted(stack_a) && ft_count_nodes(*stack_b) == 0)
		ft_putstr("\e[1m\e[32mOK\n\x1B[0m");
	else
		ft_putstr("\e[1m\x1B[31mKO\n\x1B[0m");
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
		read_from_stdin(&stack_a, &stack_b);
	}
	ft_destroy_list(&stack_a);
	ft_destroy_list(&stack_b);
	return (0);
}
