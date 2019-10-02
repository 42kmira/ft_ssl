/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:19:53 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 21:57:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*iter;
	int				delta;

	iter = b;
	delta = 0;
	while ((len = len - delta))
		if (len >= 8 && (delta = 8))
		{
			iter[len - 1] = c;
			iter[len - 2] = c;
			iter[len - 3] = c;
			iter[len - 4] = c;
			iter[len - 5] = c;
			iter[len - 6] = c;
			iter[len - 7] = c;
			iter[len - 8] = c;
		}
		else if (len >= 1 && (delta = 1))
			iter[len - 1] = c;
	return (b);
}
