/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:00:19 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 21:48:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n bytes from src into dst.
** Copy is done from the tail of src.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*iter;
	int				delta;

	iter = dst;
	delta = 0;
	while ((n = n - delta))
		if (n >= 8 && (delta = 8))
		{
			iter[n - 1] = ((unsigned char *)src)[n - 1];
			iter[n - 2] = ((unsigned char *)src)[n - 2];
			iter[n - 3] = ((unsigned char *)src)[n - 3];
			iter[n - 4] = ((unsigned char *)src)[n - 4];
			iter[n - 5] = ((unsigned char *)src)[n - 5];
			iter[n - 6] = ((unsigned char *)src)[n - 6];
			iter[n - 7] = ((unsigned char *)src)[n - 7];
			iter[n - 8] = ((unsigned char *)src)[n - 8];
		}
		else if (n >= 2 && (delta = 2))
		{
			iter[n - 1] = ((unsigned char *)src)[n - 1];
			iter[n - 2] = ((unsigned char *)src)[n - 2];
		}
		else if (n >= 1 && (delta = 1))
			iter[n - 1] = ((unsigned char *)src)[n - 1];
	return (dst);
}
