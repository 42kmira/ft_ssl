/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:06:34 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 19:29:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Binary multiplication magic. -MIN * (-1)
*/

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (*str == ' ' || ('\a' <= *str && *str <= '\r'))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
