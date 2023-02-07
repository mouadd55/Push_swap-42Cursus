/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:44 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/07 15:25:00 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_qoutes(char *string, char *str)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_split(str, ' ');
	while (arr[i])
	{
		ft_strjoin(string, arr[i]);
		i++;
	}
}
