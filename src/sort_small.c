/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   CODAM C FILE                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by wmaguire      #+#    #+#                 */
/*   Updated: 1970/01/01 00:00:00 by wmaguire     ########   codam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
THIS FILE IS LICENSED UNDER THE GNU GPLv3
Copyright (C) 2022  Will Maguire

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
				- The freedom to run the program, for any purpose.
				- The freedom to study how the program works, and adapt it to your needs.
				- The freedom to redistribute copies so you can help your neighbor.
				- The freedom to improve the program, and release
				your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#include "../include/push_swap.h"

/* static void	print_stack(t_nlist	*stack) */
/* { */
/* 	ft_printf("[%d]", stack->content); */
/* 	if (stack->next) */
/* 		return (print_stack(stack->next)); */
/* 	else */
/* 		ft_putstr("\n"); */
/* } */

void	sort_two(t_nlist *list)
{
	if (list->content > list->next->content)
		ra(list);
	exit(0);
}

void	sort_three(t_nlist *list)
{
	t_nlist	*largest;

	largest = find_largest(list);
	if (largest == list->next)
		rra(&list);
	if (largest == list)
		ra(list);
	if (list->content > list->next->content)
		sa(list);
	exit (0);
}

void	sort_four(t_nlist *a, t_nlist *b)
{
	while (a != find_smallest(a))
		ra(a);
	pb(&a, &b);
	sort_three(a);
	pa(&b, &a);
	exit (0);
}

void	sort_five(t_nlist *a, t_nlist *b)
{
	int	iter;

	iter = 0;
	while (iter < 2)
	{
		while (a != find_smallest(a))
			ra(a);
		pb(&a, &b);
	}
	if (b->content < b->next->content)
		rb(b);
	sort_three(a);
	pa(&b, &a);
	pa(&b, &a);
	exit (0);
}
