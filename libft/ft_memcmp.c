/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:04:56 by kmira             #+#    #+#             */
/*   Updated: 2019/02/24 16:14:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memcmp_short(const void *s1, const void *s2, size_t n)
{
	while (n > 0 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int delta;

	delta = 1;
	while (n)
	{
		if (n >= 8)
			if (*(double *)s1 - *(double *)s2 == 0)
				delta = 8;
			else
				return (ft_memcmp_short(s1, s2, n));
		else if (n >= 1)
			if (*(char *)s1 - *(char *)s2 == 0)
				delta = 1;
			else
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
			;
		n = n - delta;
		s1 = ((char *)s1) + delta;
		s2 = ((char *)s2) + delta;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
