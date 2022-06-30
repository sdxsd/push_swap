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

static t_nlist	*value_chk(t_nlist *stack, int value)
{
	if (stack->content == value)
		return (stack);
	else if (stack->next != NULL)
		return (value_chk(stack->next, value));
	else
		return (NULL);
}

static int	chk_duplicates(t_nlist *stack)
{
	int		lsize;
	t_nlist	*ret;
	t_nlist	*index;

	index = stack;
	lsize = ft_lstsize((t_list *)stack);
	while (lsize-- > 0)
	{
		ret = value_chk(stack, index->content);
		if (ret == index || ret == NULL)
			index = index->next;
		else
			return (FALSE);
	}
	return (TRUE);
}

static void	print_stack(t_nlist	*stack)
{
	ft_printf("[%d]", stack->content);
	if (stack->next)
		return (print_stack(stack->next));
	else
		ft_putstr("\n");
}

static void	err_exit(int value, char *str)
{
	ft_putstr("Error\n");
	exit (value);
}

int	main(int argc, char *argv[])
{
	t_nlist	*stack_1;

	if (argc < 2)
		return (0);
	stack_1 = gen_stack(argv + 1);
	if (!stack_1)
		err_exit(0, "Error\n");
	if (!chk_duplicates(stack_1))
		err_exit(0, "Error\n");
	sort_two(stack_1);
	print_stack(stack_1);
}
