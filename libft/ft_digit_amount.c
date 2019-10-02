/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_amount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:58:01 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:37:43 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_amount(int c)
{
	int result;

	result = 1;
	if (c >= 0)
		c = c * -1;
	else
		result++;
	while (c <= -10)
	{
		c = c / 10;
		result++;
	}
	return (result);
}
