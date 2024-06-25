/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:26:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 20:55:01 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(char **av)
{
	char	**splited;
	int		*arr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	arr = malloc(sizeof(int) * count(av));
	if (!arr)
		return (1);
	while (av[i])
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			return (1);
		fill_arr(splited, arr, &j);
		free_arr(splited);
		i++;
	}
	if (sorted(arr, j - 1))
		return (free(arr), 1);
	return (free(arr), 0);
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

void	sort_other(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(*stack_a);
	from_a_to_b(stack_a, stack_b);
	from_b_to_a(stack_a, stack_b);
}

void	sorting_helper(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 3 || ft_lstsize(*stack_a) == 2)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		sort_other(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (is_empty(av) || is_alpha(av) || is_double(av) || check_limits(av))
	{
		return (ft_error("Error\n"), 1);
	}
	if (is_sorted(av))
		return (0);
	stack_a = init_stack(ac, av);
	sorting_helper(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
