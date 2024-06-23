/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:43:41 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/21 01:04:48 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
void	sort_three(t_stack **stack)
{
	t_stack	*curr;

	if (!*stack)
		return ;
	if (ft_lstsize(*stack) == 2)
	{
		sa(stack);
		return ;
	}
	curr = *stack;
	if (curr->data > curr->next->data && curr->data > curr->next->next->data)
		ra(stack);
	else if (curr->next->data > curr->data
		&& curr->next->data > curr->next->next->data)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

// Helper function to find the minimum element's position in the stack
int find_min_position(t_stack *stack) 
{
    int min = stack->data;
    int min_pos = 0;
    int pos = 0;
    while (stack)
	{
        if (stack->data < min) 
		{
            min = stack->data;
            min_pos = pos;
        }
        stack = stack->next;
        pos++;
    }
    return min_pos;
}

void move_min_to_top(t_stack **stack) 
{
    int min_pos = find_min_position(*stack);
    int size = ft_lstsize(*stack);
    
    if (min_pos == 0) 
		return;
    else if (min_pos <= size / 2)
	{
        while (min_pos-- > 0)
            ra(stack);
    } 
	else 
	{
        min_pos = size - min_pos;
        while (min_pos-- > 0)
            rra(stack);
    }
}

void sort_four(t_stack **stack_a, t_stack **stack_b) 
{
    move_min_to_top(stack_a);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
}

void sort_five(t_stack **stack_a, t_stack **stack_b) 
{
    move_min_to_top(stack_a);
    pb(stack_a, stack_b);
    move_min_to_top(stack_a);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
