/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:54:30 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 20:55:10 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (check_overflow(splited[i]))
			return (1);
		i++;
	}
	return (0);
}

int	min_max_help(char *splited)
{
	long	num;

	num = ft_atoi(splited);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	check_min_max(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (min_max_help(splited[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_limits(char **av)
{
	char	**splited;
	int		i;

	i = 1;
	while (av[i])
	{
		splited = ft_split(av[i], ' ');
		if (process(splited) || check_min_max(splited))
			return (1);
		free_arr(splited);
		i++;
	}
	return (0);
}

int	sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
