/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:26:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 21:20:53 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	checker(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error("Error\n");
}

int	is_sortedd(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instructions;

	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (is_empty(av) || is_alpha(av) || is_double(av) || check_limits(av))
		return (ft_error("Error\n"), 1);
	instructions = get_next_line(0);
	stack_a = init_stack(ac, av);
	while (instructions)
	{
		checker(&stack_a, &stack_b, instructions);
		free(instructions);
		instructions = get_next_line(0);
	}
	free(instructions);
	if (is_sortedd(stack_a))
		return (free_stack(&stack_a), free_stack(&stack_b),
			ft_putstr("OK\n"), 0);
	return (free_stack(&stack_a), free_stack(&stack_b), ft_putstr("KO\n"), 0);
}
