/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:08:36 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/26 17:09:00 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	proccess(char *str)
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

int	preproccess(char **av)
{
	int		i;
	int		j;
	char	**splited;

	i = 1;
	while (av[i])
	{
		j = 0;
		splited = ft_split(av[i], ' ');
		if (!splited)
			return (1);
		while (splited[j])
		{
			if (proccess(splited[j]))
				return (free_arr(splited), 1);
			j++;
		}
		free_arr(splited);
		i++;
	}
	return (0);
}
