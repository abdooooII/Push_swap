/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:26:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/04 14:52:17 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(int c)
{
	return ((c >= '0' && c <= '9') || c == ' ');
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
			if (!is_number(av[i][j]))
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

int check_dup(int *arr)
{
	int i = 0;
	int size = sizeof(arr) / 4;
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
		// int j = 0;
		// while (splited[j])
		// {
		// 	printf("%s\n", splited[j]);
		// 	j++;
		// }
		i++;
	}
	sort_int_tab(arr, j);
	if (check_dup(arr))
		return (1);
	j = 0;
	while(j < count(av))
	{
		printf("%d -- ", arr[j]);
		j++;
	}
	return (0);
}

int main(int ac, char **av)
{
    if (ac == 1)
        exit(1);
	if (is_empty(av) || is_alpha(av) || is_double(av))
		return (printf("ko"), 1);
	return (puts("ok"), 0);
}
