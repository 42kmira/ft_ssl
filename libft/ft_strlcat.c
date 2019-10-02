/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:01:22 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:13:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*head;

	head = dst;
	i = ft_strlen(src);
	dst = (char *)ft_fast_find(dst, dstsize, '\0');
	if ((size_t)(dst - head) == dstsize)
		return (dstsize + i);
	else
	{
		if (dstsize - (dst - head) <= i)
			*(char *)(ft_memcpy_at(dst, src,
						dstsize - (dst - head) - 1)) = '\0';
		else
			*(char *)(ft_memcpy_at(dst, src, i)) = '\0';
		return (dst - head + i);
	}
}
