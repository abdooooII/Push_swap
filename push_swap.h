/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 04:27:55 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/04 20:05:30 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>    
# include <string.h>
# include <limits.h>

long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
char	**ft_help(const char *end, char c, int len, char **final);
void	ft_free(char **ptr, int i);
char	*ft_strndup(const char *src, int n);
int		countword(const char *s, char c);
void	sort_int_tab(int *tab, unsigned int size);
int		ft_strlen(char *str);

#endif