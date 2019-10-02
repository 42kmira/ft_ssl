/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:09:57 by kmira             #+#    #+#             */
/*   Updated: 2019/02/24 12:56:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = dst;
	while (++i < n)
	{
		*(ptr + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
