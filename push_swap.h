/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:28:16 by moudrib           #+#    #+#             */
/*   Updated: 2023/02/28 17:12:00 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	int				data;
	int				index;
	int				rank;
	int				moves;
	struct s_list	*next;
}	t_list;

/************************* Libft functions *************************/

ssize_t	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/****************************** Utils ******************************/

void	ft_putchar(char ch);
void	ft_putstr(char *str);
char	**ft_free_arr(char **str);
int		ft_count_words(char const *s, char c);

/***************************** Parsing *****************************/

int		ft_limits(char **av);
int		ft_isdigit(char *str);
int		ft_duplicates(t_list *head);
int		ft_is_sorted(t_list **stack_a);
void	ft_error(t_list **stack_a, t_list **stack_b);
void	ft_first_check(char **av, t_list **stack_a, t_list **stack_b);

/**************************** List utils ***************************/

t_list	*ft_lstnew(int data, int index, int rank);
t_list	*ft_lstlast(t_list *head);
void	ft_sort_rank(t_list *stack_a);
void	*ft_destroy_list(t_list **head);
void	ft_lstadd_back(t_list **head, t_list *new);

/*********************** Swap instructions *************************/

void	ft_sa(t_list **stack_a, int i);
void	ft_sb(t_list **stack_b, int i);
void	ft_ss(t_list **stack_a, t_list **stack_b, int i);

/*********************** Push instructions *************************/

void	ft_pb(t_list **stack_a, t_list **stack_b, int i);
void	ft_pa(t_list **stack_b, t_list **stack_a, int i);

/********************** Rotate instructions ************************/

void	ft_ra(t_list **stack_a, int i);
void	ft_rb(t_list **stack_b, int i);
void	ft_rr(t_list **stack_a, t_list **stack_b, int i);

/****************** Reverse rotate instructions ********************/

void	ft_rra(t_list **stack_a, int i);
void	ft_rrb(t_list **stack_b, int i);
void	ft_rrr(t_list **stack_a, t_list **stack_b, int i);

/************************** Sorting utils **************************/

int		ft_count_nodes(t_list *head);
int		ft_index_util(t_list *stack_a);
int		ft_smallest(t_list *stack_a, int rank);
void	ft_bring_to_top(t_list **stack_a, int index);

/************************* Stack size <= 5 *************************/

void	ft_stack_size_2(t_list **stack_a);
void	ft_stack_size_3(t_list **stack_a);
void	ft_stack_size_4(t_list **stack_a, t_list **stack_b);
void	ft_stack_size_5(t_list **stack_a, t_list **stack_b);

/******************* Stack size > 5 && <= 500 **********************/

void	ft_moves(t_list **stack);
void	ft_reindexing(t_list **stack);
t_list	*ft_find_first_max(t_list **stack_b);
t_list	*ft_find_second_max(t_list **stack_b);
void	ft_stack_size(t_list **stack_a, t_list **stack_b);
void	ft_stack_size_100(t_list **stack_a, t_list **stack_b);
void	ft_stack_size_500(t_list **stack_a, t_list **stack_b);
void	ft_push_to_a(t_list **stack_b, t_list **stack_a, int rank);
void	ft_push_back_to_stack_a(t_list **stack_b, t_list **stack_a);
void	ft_push_chunk(t_list **stack_a, t_list **stack_b, int start, int end);

/************************** Get next line **************************/

char	*save_rest(char *buf);
char	*get_next_line(int fd);
int		search_newline(char *s);
char	*read_line(int fd, char *buf);
char	*ft_strjoin(char *s1, char *s2);

/****************************** Bonus ******************************/

int		ft_strcmp(const char *s1, const char *s2);
void	ft_execute_instructions(t_list **stack_a, t_list **stack_b, char *str);

#endif
