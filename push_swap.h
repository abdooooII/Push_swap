/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:27:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 21:06:31 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>    
# include <string.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				position;
	int				data;
	struct s_stack	*next;
}	t_stack;

int			check_limits(char **av);
int			sorted(int *arr, int size);
void		fill_arr(char **av, int *arr, int *j);
int			check_dup(int *arr, int size);
void		free_arr(char **arr);
int			is_double(char **av);
int			check_overflow(char *splited);
int			process(char **splited);
int			min_max_help(char *splited);
int			check_min_max(char **splited);
int			is_number(int c);
int			is_num(char c);
int			is_alpha(char **av);
int			is_empty(char **av);
int			count(char **av);
int			ft_lstsize(t_stack *lst);
long		ft_atoi(const char *str);
char		**ft_split(const char *s, char c);
char		**ft_help(const char *end, char c, int len, char **final);
void		ft_free(char **ptr, int i);
char		*ft_strndup(const char *src, int n);
int			countword(const char *s, char c);
void		sort_int_tab(int *tab, unsigned int size);
int			ft_strlen(char *str);
t_stack		*ft_lstnew(int data);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		init(t_stack **stack_a, int data);
t_stack		*init_stack(int ac, char **av);
int			rotate(t_stack **stack);
int			ra(t_stack **stack_a);
int			rb(t_stack **stack_b);
int			rr(t_stack **stack_a, t_stack **stack_b);
int			pa(t_stack **src, t_stack **dest);
int			pb(t_stack **src, t_stack **dest);
int			push(t_stack **src, t_stack **dest);
void		ft_swap(int *a, int *b);
int			swap(t_stack **stack);
int			sa(t_stack **stack_a);
int			sb(t_stack **stack_b);
int			ss(t_stack **stack_a, t_stack **stack_b);
int			reverse_rotate(t_stack	**stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);
int			rrb(t_stack **stack_b);
int			rra(t_stack **stack_a);
int			ft_lstsize(t_stack *lst);
void		sort_three(t_stack **stack);
t_stack		*before_last(t_stack *stack);
int			find_min_position(t_stack *stack);
void		move_min_to_top(t_stack **stack);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		initialize_indices(t_stack *stack);
void		index_stack(t_stack *stack);
void		from_b_to_a(t_stack **stack_a, t_stack **stack_b);
int			max_index(t_stack *head);
void		stack_position(t_stack *a);
void		from_a_to_b(t_stack **stack_a, t_stack **stack_b);
void		ft_error(char *str);
void		ft_putstr(char *str);
#endif