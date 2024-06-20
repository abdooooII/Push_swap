/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:55:59 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/20 13:09:27 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **src,  t_stack **dest)
{
	t_stack	*current;
	
	if(!src || !*src)
		return (1);
	current = (*src);
	(*src) = (*src)->next;
	current->next = NULL;
	if (!*dest)
		(*dest) = current;
	else
		ft_lstadd_front(dest, current);
	return (0);	
}

int	pa(t_stack **src, t_stack **dest)
{
	if(push(dest, src))
		return(1);
	ft_putstr("pa\n");
	return(0);
}

int	pb(t_stack **src, t_stack **dest)
{
	if(push(src, dest))
		return(1);
	ft_putstr("pb\n");
	return(0);
}
