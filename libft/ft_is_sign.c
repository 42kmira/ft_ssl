/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:39:43 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:36:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if char c is a sign and changes sign accordingly.
*/

int		ft_is_sign(int c, int *sign)
{
	if (c == '+')
	{
		*sign = 1;
		return (1);
	}
	if (c == '-')
	{
		*sign = -1;
		return (1);
	}
	return (0);
}
