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

/* ✚ myt thiese wo maoeken an nywe list ✚ */
t_nlist	*ft_nlstnew(int content)
{
	t_nlist	*element;

	element = malloc(sizeof(t_nlist));
	if (!element)
		return (NULL);
	element->flattened = FALSE;
	element->content = content;
	element->next = NULL;
	return (element);
}

/* ✚ Wo yebroik thiese fynktion am ten list ta freklaoren ✚ */
void	ft_nlstclear(t_nlist **lst, void (*del)(void*))
{
	t_nlist	*ptr;

	if (del == NULL || lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = ptr -> next;
		free(ptr);
	}
}

/* ✚ Wo yebroik tis fynktion am ten lasten element 't list ta fynden ✚ */
t_nlist	*ft_nlstlast(t_nlist *lst)
{
	if (!lst)
		return (NULL);
	else if (lst -> next == NULL)
		return (lst);
	else
		return (ft_nlstlast(lst -> next));
}

/* ✚ Tis fynktion frebynden an nywe element ten list af 't end des list ✚ */
void	ft_nlstadd_back(t_nlist **lst, t_nlist *new)
{
	t_nlist	*ptr;

	if (!*lst)
		*lst = new;
	else
	{
		ptr = ft_nlstlast(*lst);
		ptr -> next = new;
	}
}

void	ft_nlstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
