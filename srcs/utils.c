/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:44:48 by kmira             #+#    #+#             */
/*   Updated: 2019/10/13 21:01:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

void	ft_strnrev(char *str, size_t n)
{
	size_t	i;
	char	container;

	i = 0;
	n = n - 1;
	while (i < n)
	{
		container = str[i];
		str[i] = str[n];
		str[n] = container;
		n--;
		i++;
	}
}

size_t		ft_strncpy_i(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}
