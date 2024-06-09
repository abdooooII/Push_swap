/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:27:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/08 19:35:28 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>    
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int	data;
	struct	s_stack *next;
} t_stack;

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
int 		rr(t_stack **stack_a, t_stack **stack_b);
int			pa(t_stack **src, t_stack **dest);
int			pb(t_stack **src, t_stack **dest);
int			push(t_stack **src,  t_stack **dest);
int			swap(t_stack **stack);
int			sa(t_stack **stack_a);
int 		sb(t_stack **stack_b);
int 		ss(t_stack **stack_a, t_stack **stack_b);
int			reverse_rotate(t_stack	**stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);
int			rrb(t_stack **stack_b);
int			rra(t_stack **stack_a);
int			ft_lstsize(t_stack *lst);
void		sort_three(t_stack **stack);
t_stack		*before_last(t_stack *stack);

#endif