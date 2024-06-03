/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:26:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/16 00:21:47 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_spaces(char **av)
 {
    int  i;
    int  j;
    int  spaces;
    
    i = 0;
    while(av[i])
    {
        j = 0;
        spaces = 0;
        while(av[i][j])
        {
            if(av[i][j] == ' ')
                spaces++;
            j++;
        }
        if((int)strlen(av[i]) == spaces)
        {
            printf("saadouda");
            return(1);
        }
        i++;
    }
    return (0);
 }

 int check_alpha(char **av)
 {
    int  i;
    int  j;
    
    i = 0;
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if((av[i][j] >= 65 && av[i][j] >= 90) || (av[i][j] >= 97 && av[i][j] >= 122))
                return(1);
            j++;
        }
        i++;
    }
    return (0);
 }

void    parsing(int ac, char **av)
{
    (void)ac;
    if (check_spaces(av) == 1 || check_alpha(av) == 1)
        printf("hello\n");
    else
        return ;
}

int main(int ac, char **av)
{
    (void) *av;
    if (ac == 1)
        exit(1);
    parsing(ac, av);
}