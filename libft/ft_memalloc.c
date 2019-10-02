/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:10:54 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:21:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(sizeof(char) * (size));
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size);
	return (result);
}
