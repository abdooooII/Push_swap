/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:01:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/25 20:52:24 by abouafso         ###   ########.fr       */
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

int proccess(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_alpha(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (proccess(av[i]))
			return (1);
		while (av[i][j])
		{
			if (av[i][j + 1] && (av[i][j] == '-'
				|| av[i][j] == '+') && is_num(av[i][j + 1]))
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

int	is_empty(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			return (1);
		i++;
	}
	return (0);
}

int	count(char **av)
{
	int	counter;
	int	i;

	counter = 0;
	i = 1;
	while (av[i])
	{
		counter += countword(av[i], ' ');
		i++;
	}
	return (counter);
}
