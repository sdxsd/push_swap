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

static void	add_content(t_nlist *stack, char *argv[])
{
	int	num;

	num = ft_atoi(*argv);
	stack->content = num;
	argv++;
	if (stack->next)
		return (add_content(stack->next, argv));
	else
		return ;
}

static void	print_stack(t_nlist	*stack)
{
	ft_printf("[%d]", stack->content);
	if (stack->next)
		return (print_stack(stack->next));
	else
		ft_putstr("\n");
}

/* ✚ Ie muden maoeken nywe fynktionen foar ten yebroik fan */
/* thie nlist type. Klaor yetan [✓] ✚  */
static t_nlist	*gen_stack(int stack_size)
{
	t_nlist	*first_element;
	t_nlist	*new_element;
	int		iter;

	iter = 0;
	first_element = NULL;
	new_element = NULL;
	while (iter < stack_size)
	{
		new_element = ft_nlstnew(0);
		if (!new_element)
			ft_nlstclear(&first_element, &free);
		ft_nlstadd_back(&first_element, new_element);
		iter++;
	}
	return (first_element);
}

int	main(int argc, char *argv[])
{
	t_nlist	*stack_1;
	/* t_list	*stack_2; */

	if (argc < 2)
		return (0);
	stack_1 = gen_stack(argc - 1);
	/* stack_2 = gen_stack(argc - 1); */
	add_content(stack_1, argv + 1);
	print_stack(stack_1);
	sort_two(stack_1);
}
