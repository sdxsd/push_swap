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

/* Moves all elements in t_list *lst up by 1. */
void	rotate(t_nlist *up)
{
	int	tmp;

	if (ft_lstsize((t_list *)up) > 1)
	{
		tmp = up->content;
		up->content = up->next->content;
		up->next->content = tmp;
		return (rotate(up->next));
	}
	else
		return ;
}

/* Simple wrapper. */
void	ra(t_nlist *up)
{
	rotate(up);
	ft_putstr("ra\n");
}

/* Simple wrapper. */
void	rb(t_nlist *up)
{
	rotate(up);
	ft_putstr("rb\n");
}

/* Simple wrapper. */
void	rr(t_nlist *a, t_nlist *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
