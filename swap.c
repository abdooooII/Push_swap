/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:49:12 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/14 04:43:38 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b) 
{
    int tmp;
	
	tmp = *a;
    *a = *b;
    *b = tmp;
}

int swap(t_stack **stack)
{
    t_stack *head;
    t_stack *next;

    if (!stack || !*stack || !(*stack)->next)
        return (1);

    head = (*stack);
    next = head->next;
    
    ft_swap(&head->data, &next->data);

    return (0);
}

int sa(t_stack **stack_a)
{
	if(swap(stack_a))
		return(1);
	printf("sa\n");
	return(0);
}

int sb(t_stack **stack_b)
{
	if(swap(stack_b))
		return(1);
	printf("sb\n");
	return(0);
}

int ss(t_stack **stack_a, t_stack **stack_b)
{
	if(swap(stack_a) || swap(stack_b))
		return(1);
	printf("ss\n");
	return(0);
}