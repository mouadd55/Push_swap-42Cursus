/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:05 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/07 17:13:52 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

ssize_t	ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char ch);
int		ft_isdigit(char *str);
char	**free_arr(char **str);
int		count_words(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
/************************* List utils *************************/
t_list	*create_node(int data);
void	insert_at_end(t_list **head, t_list *new);
void	first_check(char **av, t_list **head);

#endif
