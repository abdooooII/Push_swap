/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:03:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 16:32:05 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init(t_stack **stack_a, int data)
{
	if (!*stack_a)
		*stack_a = ft_lstnew(data);
	else
		ft_lstadd_back(stack_a, ft_lstnew(data));
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*stack_a;
	int			data;
	int			i;
	int			j;
	char		**splited;

	stack_a = NULL;
	data = 0;
	i = 0;
	while (++i < ac)
	{
		splited = ft_split(av[i], ' ');
		if (!splited)
			return (NULL);
		j = -1;
		while (splited[++j])
		{
			data = ft_atoi(splited[j]);
			init(&stack_a, data);
			free(splited[j]);
		}
		free(splited);
	}
	return (stack_a);
}
