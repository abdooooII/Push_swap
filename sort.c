/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:43:41 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/09 00:02:57 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	sort_four()
	