/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/03 15:34:07 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr("\x1B[31mError\x1B[0m");
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	j = 0;
	if (ac >= 1)
	{
		while (av[i])
		{
			if (ft_word(av[i], ' ') > 1)
			{
				arr = ft_split(av[i], ' ');
				while (j < ft_word(av[i], ' '))
				{
					if (ft_isdigit(arr[j]))
						ft_error();
					j++;
				}
			}
			else if (ft_isdigit(av[i]))
				ft_error();
			i++;
		}
	}
}
