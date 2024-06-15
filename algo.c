/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:29:49 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/15 01:26:33 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void index_stack(t_stack *stack) {
    int index = 0;
    int size = ft_lstsize(stack);


	t_stack *tmp = stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}

    while (index < size) {
        t_stack *current = stack;
        t_stack *min_node = NULL;
        while (current) {
            if (current->index == -1 && (!min_node || current->data < min_node->data)) {
                min_node = current;
            }
            current = current->next;
        }
        if (min_node) {
            min_node->index = index++;
        }
    }
}

void	from_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int pivot_range = 16;

	if (ft_lstsize(*stack_a) >= 100)
		pivot_range = 33;
	int i = 0;

	while(ft_lstsize(*stack_a))
	{
		if((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + pivot_range))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;		
		}
		else
			ra(stack_a);
	}
}

void	stack_position(t_stack *a)
{
	if (!a)
		return ;
	t_stack *tmp = a;
	int i = 0;
	while(tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}	
}

int max_index(t_stack *head)
{
	t_stack *tmp = head;
	t_stack *max = head;

	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position);
}


void from_b_to_a (t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(*stack_b))
	{
		stack_position(*stack_b);
		int size = ft_lstsize(*stack_b);
		int m_index = max_index(*stack_b);
			if (m_index == 0)
				pa(stack_a, stack_b);
			else if (m_index < (size / 2))
			{
				int nb1 = size - m_index;
				while (nb1--)
					rb(stack_b);
				pa(stack_a, stack_b);
			}
			else if (m_index >= (size / 2))
			{
				int nb = size - m_index;
				while (nb--)
					rrb(stack_b);
				pa(stack_a, stack_b);
			}
		}
}