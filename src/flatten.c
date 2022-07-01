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
#include <limits.h>

/* Flattens the numbers for use in the radix sort algorithm. */
int	flatten_nums(t_nlist *list)
{
	static int	index;
	t_nlist		*smallest;

	smallest = find_smallest(list);
	smallest->content = index;
	index++;
	if (index != ft_lstsize((t_list *)list) && list->next)
		return (flatten_nums(list->next));
	else
		return (index = 0);
}

/* Returns the position of the smallest integer in the list. */
t_nlist	*find_smallest(t_nlist *list)
{
	int		last_smallest;
	t_nlist	*smallest;

	last_smallest = INT_MAX;
	if (!list)
		return (0);
	while (TRUE)
	{
		if (list->content < last_smallest)
		{
			last_smallest = list->content;
			smallest = list;
		}
		if (list->next)
			list = list->next;
		else
			break ;
	}
	return (smallest);
}

/* Returns the position of the largest integer within the list. */
t_nlist	*find_largest(t_nlist *list)
{
	int		last_largest;
	t_nlist	*largest;

	last_largest = INT_MIN;
	if (!list)
		return (0);
	while (TRUE)
	{
		if (list->content > last_largest)
		{
			last_largest = list->content;
			largest = list;
		}
		if (list->next)
			list = list->next;
		else
			break ;
	}
	return (largest);
}
