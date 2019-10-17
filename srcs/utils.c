/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:44:48 by kmira             #+#    #+#             */
/*   Updated: 2019/10/17 10:55:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_main.h"

/*
** The conversion of endianness works in the following way:
** BASE:     1010 2010 | 3010 4010 | 5010 6010 | 7010 8010
** 8_SHIFT:  3010 4010 | 1010 2010 | 7010 8010 | 5010 6010
** 16_SHIFT: 7010 8010 | 5010 6010 | 3010 4010 | 1010 2010
*/

u_int32_t	convert_endian_32bits(u_int32_t val)
{
	u_int32_t x;

	x = ((0XFF00FF00 & val) >> 8) | ((0X00FF00FF & val) << 8);
	x = ((0XFFFF0000 & x) >> 16) | ((0X0000FFFF & x) << 16);
	return (x);
}

void		ft_strnrev(char *str, size_t n)
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
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}
