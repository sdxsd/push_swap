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

static void	add_content(t_list *stack, char	*argv[])
{
	long	num;

	num = ft_atoi(*argv);
	ft_memmove(stack->content, &num, sizeof(long));
	argv++;
	if (stack->next)
		return (add_content(stack->next, argv));
	else
		return ;
}

static void	print_stack(void *content)
{
	long	*long_content;

	long_content = content;
	ft_printf("+---+\n%d\n", *long_content);
}

static t_list	*gen_stack(int stack_size)
{
	t_list	*first_element;
	t_list	*new_element;
	int		iter;

	iter = 0;
	first_element = NULL;
	new_element = NULL;
	while (iter < stack_size)
	{
		new_element = ft_lstnew(calloc(sizeof(long), 1));
		if (!new_element)
			ft_lstclear(&first_element, &free);
		ft_lstadd_back(&first_element, new_element);
		iter++;
	}
	return (first_element);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_1;
	t_list	*stack_2;

	if (argc < 2)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	stack_1 = gen_stack(argc - 1);
	stack_2 = gen_stack(argc - 1);
	add_content(stack_1, argv + 1);
	ft_printf("STACK 1:\n");
	ft_lstiter(stack_1, &print_stack);
	ft_printf("+---+\nSTACK 2:\n");
	ft_lstiter(stack_2, &print_stack);
	ft_lstclear(&stack_1, &free);
	ft_lstclear(&stack_2, &free);
	push(stack_1, stack_2);
	ft_printf("STACK 1:\n");
	ft_lstiter(stack_1, &print_stack);
	ft_printf("+---+\nSTACK 2:\n");
	ft_lstiter(stack_2, &print_stack);
}
