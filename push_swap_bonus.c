/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:26:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/20 20:02:52 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_number(int c)
{
	return ((c >= '0' && c <= '9') || c == ' ');
}

int	is_num(char c)
{
	if (!c)
		return (0);
	return (c >= '0' && c <= '9');
}

int	is_alpha(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			if (av[i][j + 1] && (av[i][j] == '-' || av[i][j] == '+') && is_num(av[i][j + 1]))
			{
				j++;
				continue ;
			}	
			else if (!is_number(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int is_empty(char **av)
{
	int i = 1;
	while(av[i])
	{
		int j = 0;
		while(av[i][j] == ' ')
			j++;
		if(!av[i][j])
			return (1);
		i++;
	}
	return(0);
}

int	count(char **av)
{
	int counter = 0;
	int i = 1;
	
	while(av[i])
	{
		counter += countword(av[i], ' ');
		i++;
	}
	return (counter);
}
void	fill_arr(char **av, int *arr, int *j)
{
	int i = 0;
	while (av[i])
	{
		arr[*j] = ft_atoi(av[i]);
		i++;
		(*j)++;
	}
}

int check_dup(int *arr, int size)
{
	int i = 0;
	while(i < size)
	{
		if(arr[i] == arr[i + 1])
			return(1);
		i++;
	}
	return (0);
}

void	free_arr(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int is_double(char **av)
{
	char	**splited;
	int		*arr;

	int i = 1;
	int j = 0;
	arr = malloc(sizeof(int) * count(av));
	if (!arr)
		return(1);
	while(av[i])
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			return (1);
		fill_arr(splited, arr, &j);
		free_arr(splited);
		i++;
	}
	sort_int_tab(arr, j);
	if (check_dup(arr, j - 1))
		return (free(arr), 1);
	return (free(arr), 0);
}

int	check_overflow(char *splited)
{
	int j = 0;
	int len;

	if (splited[j] == '+' || splited[j] == '-')
		j++;
	while(splited[j] == '0')
		j++;
	len = ft_strlen(splited + j);
	if (len > 11)
		return (1);
	return(0);
}

int	process(char **splited)
{
	int	i = 0;

	while(splited[i])
	{
		if (check_overflow(splited[i]))
			return (1);
		i++;
	}
	return 0;
}
int	min_max_help(char *splited)
{
	long num = ft_atoi(splited);
	
	if(num > INT_MAX || num < INT_MIN)
		return (1);
	return(0);
}

int	check_min_max(char **splited)
{
	int i = 0;

	while(splited[i])
	{
		if(min_max_help(splited[i]))
			return (1);
		i++;
	}
	return(0);
}

int	check_limits(char **av)
{
	char **splited;
	int	i = 1;
	
	while(av[i])
	{
		splited = ft_split(av[i], ' ');
		if (process(splited) || check_min_max(splited))
			return (1);
		free_arr(splited);
		i++;
	}
	return 0;
}

int	sorted(int *arr, int size)
{
	int i = 0;

	while (i < size)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(char **av)
{
	char	**splited;
	int		*arr;

	int i = 1;
	int j = 0;
	arr = malloc(sizeof(int) * count(av));
	if (!arr)
		return(1);
	while(av[i])
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

void sort_other(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(*stack_a);
	from_a_to_b(stack_a, stack_b);
	from_b_to_a(stack_a, stack_b);
}

void sorting_helper(t_stack **stack_a, t_stack **stack_b)
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

void	checker(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if(!ft_strcmp(instruction, "pa\n"))
		pa(stack_a, stack_b);
	else if(!ft_strcmp(instruction, "pb\n"))
		pb(stack_a, stack_b);
	else if(!ft_strcmp(instruction, "sa\n"))
		sa(stack_a);
	else if(!ft_strcmp(instruction, "sb\n"))
		sb(stack_b);
	else if(!ft_strcmp(instruction, "ss\n"))
		ss(stack_a, stack_b);
	else if(!ft_strcmp(instruction, "ra\n"))
		ra(stack_a);
	else if(!ft_strcmp(instruction, "rb\n"))
		rb(stack_b);
	else if(!ft_strcmp(instruction, "rr\n"))
		rr(stack_a, stack_b);
	else if(!ft_strcmp(instruction, "rra\n"))
		rra(stack_a);
	else if(!ft_strcmp(instruction, "rrb\n"))
		rrb(stack_b);
	else if(!ft_strcmp(instruction, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error("Error\n");
}

int is_sortedd(t_stack *stack_a)
{
    // Traverse the stack
    while (stack_a && stack_a->next)
    {
        if (stack_a->data > stack_a->next->data)
            return 0;
        stack_a = stack_a->next;
    }
    return 1;
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	*instructions;

	stack_b = NULL;
	if (ac == 1)
		return (0);
    if (is_empty(av) || is_alpha(av) || is_double(av) || check_limits(av))
		return (ft_error("Error\n"), 1);
	instructions = get_next_line(0);
	if (is_sorted(av))
		return(free(instructions), ft_putstr("OK\n"), 0);
	stack_a = init_stack(ac, av);
	while(instructions)
	{
		checker(&stack_a, &stack_b, instructions);
		free(instructions);
		instructions = get_next_line(0);
	}
	free(instructions);
	if(is_sortedd(stack_a))
		return(free_stack(&stack_a), free_stack(&stack_b), ft_putstr("OK\n"), 0);
	return(free_stack(&stack_a), free_stack(&stack_b), ft_putstr("KO\n"), 0);
}
