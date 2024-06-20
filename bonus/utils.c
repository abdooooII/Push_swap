/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:55:12 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/20 12:31:40 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *str)
{
	int	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}

void ft_error(char *str)
{
	int	i = 0;
	while(str[i])
		write(2, &str[i++], 1);
	exit(EXIT_FAILURE);
}

int ft_strcmp(const char *s1, const char *s2)
{
    unsigned char *str1;
    unsigned char *str2;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;

    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}
long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int	tmp;

	while(i < size - 1)
	{
		if(tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}