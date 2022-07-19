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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

/* ✚ Myn lyst fur ten yebroik inse ten push_swap proyyrama ✚ */
typedef struct s_num_list {
	bool				flattened;
	int					content;
	struct s_num_list	*next;
}	t_nlist;

/* UTIL FUNCTIONS */
int		free_ptr_array(char *ptr[]);

/* LIST FUNCTIONS */
t_nlist	*ft_nlstnew(int content);
void	ft_nlstclear(t_nlist **lst, void (*del)(void*));
void	ft_nlstadd_back(t_nlist **lst, t_nlist *new);
t_nlist	*ft_nlstlast(t_nlist *lst);
void	ft_nlstadd_front(t_nlist **lst, t_nlist *new);

/* INPUT FUNCTIONS */
t_nlist	*gen_stack(char	**content);
t_nlist	*string_to_list(t_nlist *list, char *content);
int		chk_argv(char **argv);

/* ROTATE FUNCTIONS */
void	rotate(t_nlist *up);
void	rr(t_nlist *a, t_nlist *b);
void	ra(t_nlist *up);
void	rb(t_nlist *up);

/* REVERSE ROTATE FUNCTIONS */
void	reverse_rotate(t_nlist **list);
void	rra(t_nlist **list);
void	rrb(t_nlist **list);
void	rrr(t_nlist **a, t_nlist **b);

/* PUSH FUNCTIONS */
void	push(t_nlist **from, t_nlist **to);
void	pa(t_nlist **from, t_nlist **to);
void	pb(t_nlist **from, t_nlist **to);

/* FLATTEN FUNCTIONS */
t_nlist	*find_largest(t_nlist *list);
t_nlist	*find_smallest(t_nlist *list);
int		flatten_nums(t_nlist *list);

/* SWAP FUNCTIONS */
void	swap(t_nlist *head);
void	sa(t_nlist *head);
void	sb(t_nlist *head);
void	ss(t_nlist *a, t_nlist *b);

/* SORTING FUNCTIONS */
void	sort_small(t_nlist *a, t_nlist *b);
void	sort_two(t_nlist *list);
void	sort_three(t_nlist *list);
void	sort_four(t_nlist *a, t_nlist *b);
void	sort_five(t_nlist *a, t_nlist *b);
void	radix_sort(t_nlist *list_a, t_nlist *list_b, int size, int largest_int);

#endif // PUSH_SWAP_H
