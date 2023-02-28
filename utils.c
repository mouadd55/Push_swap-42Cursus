/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:02 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/28 19:44:01 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	search_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
