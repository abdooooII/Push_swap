/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:16:19 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 21:16:45 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	fill_arr(char **av, int *arr, int *j)
{
	int	i;

	i = 0;
	while (av[i])
	{
		arr[*j] = ft_atoi(av[i]);
		i++;
		(*j)++;
	}
}

int	check_dup(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_double(char **av)
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
	sort_int_tab(arr, j);
	if (check_dup(arr, j - 1))
		return (free(arr), 1);
	return (free(arr), 0);
}

int	check_overflow(char *splited)
{
	int	j;
	int	len;

	j = 0;
	if (splited[j] == '+' || splited[j] == '-')
		j++;
	while (splited[j] == '0')
		j++;
	len = ft_strlen(splited + j);
	if (len > 11)
		return (1);
	return (0);
}
