/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:26:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/04 20:22:39 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		i++;
	}
	sort_int_tab(arr, j);
	if (check_dup(arr, j - 1))
		return (1);
	return (0);
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
		i++;
	}
	if (sorted(arr, j - 1))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
    if (ac == 1 || is_empty(av) || is_alpha(av) || is_double(av) || check_limits(av))
		return (printf("ko\n"), 1);
	if (is_sorted(av))
		return (0);
	return (puts("ok"), 0);
}
