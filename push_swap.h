/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:28:16 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/11 10:59:58 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

void	ft_error(t_list **head);
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
int		check_duplicates(t_list *head);
int		is_sorted(t_list *head);
/************************* List utils *************************/
t_list	*create_node(int data);
void	insert_at_end(t_list **head, t_list *new);
void	first_check(char **av, t_list **head);
void	*clear_list(t_list **head);

#endif
