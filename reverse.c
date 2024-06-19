/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:16:32 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/17 09:54:54 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack	**stack)
{
	t_stack	*tmp;
	t_stack	*bef_last;
	t_stack	*last;

	if(!stack || !(*stack) || !(*stack)->next)
		return(1);
	last = ft_lstlast(*stack);
	bef_last = before_last(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	bef_last->next = NULL;
	return(0);
}

int	rra(t_stack **stack_a)
{
	if(reverse_rotate(stack_a))
		return(1);
	printf("rra\n");
	return(0);
}

int	rrb(t_stack **stack_b)
{
	if(reverse_rotate(stack_b))
		return(1);
	printf("rrb\n");
	return(0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if(reverse_rotate(stack_a) || reverse_rotate(stack_b))
		return(1);
	printf("rrr\n");
	return(0);
}