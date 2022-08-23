/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaguire <wmaguire@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:25:01 by keizerrijk        #+#    #+#             */
/*   Updated: 2021/10/26 15:00:36 by wmaguire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	iterator;

	ptr = s;
	iterator = 0;
	while (iterator < n)
	{
		ptr[iterator] = 0;
		++iterator;
	}
}
