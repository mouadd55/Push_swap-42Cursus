/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:27:30 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/11 13:11:35 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;

	i = 0;
	if (s == 0)
		return (0);
	str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (str == 0)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			str[i] = ft_substr(s, 0, ft_lenword(s, c));
			if (str[i] == 0)
				return (free_arr(str));
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	str[i] = 0;
	return (str);
}
