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


static int	chk_individual(char	*argv)
{
	if (ft_strlen(argv) > 1 && argv[0] == '-')
	{
		if (!ft_isdigit(argv[1]))
			return (FALSE);
		else
			argv++;
	}
	while (*argv != '\0')
	{
		if (!ft_isdigit(*argv))
			return (FALSE);
		else
			argv++;
	}
	return (TRUE);
}

static int	chk_list(char *argv)
{
	char	**tmp_strarray;

	tmp_strarray = ft_split(argv, ' ');
	while (*tmp_strarray)
	{
		if (!chk_individual(*tmp_strarray))
			return (FALSE);
		free(*tmp_strarray);
		tmp_strarray++;
	}
	return (TRUE);
}

int	chk_argv(char **argv)
{
	while (*argv)
	{
		if (ft_strchr(*argv, ' '))
		{
			if (!chk_list(*argv))
				return (FALSE);
		}
		else if (!chk_individual(*argv))
				return (FALSE);
		argv++;
	}
	return (TRUE);
}

t_nlist	*string_to_list(t_nlist *list, char *content)
{
	char	**content_array;
	t_nlist	*sublist;

	content_array = ft_split(content, ' ');
	if (!content_array)
		return (NULL);
	sublist = gen_stack(content_array);
	ft_nlstadd_back(&list, sublist);
	return (list);
}

t_nlist	*gen_stack(char	**content)
{
	t_nlist	*first_element;
	t_nlist	*new_element;

	first_element = NULL;
	new_element = NULL;
	while (*content != NULL)
	{
		if (ft_strchr(*content, ' '))
		{
			if (first_element == NULL)
				first_element = string_to_list(first_element, *content);
			else
				string_to_list(first_element, *content);
			content++;
		}
		else
		{
			new_element = ft_nlstnew(ft_atoi(*content));
			if (!new_element)
				ft_nlstclear(&first_element, &free);
			ft_nlstadd_back(&first_element, new_element);
			content++;
		}
	}
	return (first_element);
}
