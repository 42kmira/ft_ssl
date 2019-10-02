/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:50:45 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 21:56:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If 8 bytes need to zero, do it in one go with the use of of a double.
** If less than 8 bytes need to be zeroed, do it in one go with char.
** decrement size remaining by delta, and move the pointer 'up' by delta.
*/

void	ft_bzero(void *s, size_t n)
{
	int delta;

	delta = 1;
	while (n)
	{
		if (n >= 8)
		{
			*(double *)s = 0;
			delta = 8;
		}
		else if (n >= 1)
		{
			*(char *)s = 0;
			delta = 1;
		}
		n = n - delta;
		s = ((char *)s) + delta;
	}
}
