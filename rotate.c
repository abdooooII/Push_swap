/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:36:42 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 15:33:33 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	tmp = (*stack);
	(*stack) = (*stack)->next;
	last = ft_lstlast(*stack);
	tmp->next = NULL;
	last->next = tmp;
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		return (1);
	ft_putstr("ra\n");
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		return (1);
	ft_putstr("rb\n");
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) || rotate(stack_b))
		return (1);
	ft_putstr("rr\n");
	return (0);
}
