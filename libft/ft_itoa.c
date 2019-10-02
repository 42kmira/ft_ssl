/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:58:18 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:34:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	char	*head;
	int		digits;

	digits = ft_digit_amount(n);
	if (!(result = malloc(sizeof(*result) * (digits + 1))))
		return (NULL);
	head = result;
	if (n >= 0)
		n = n * -1;
	else
	{
		*result++ = '-';
		digits--;
	}
	*(result + digits) = '\0';
	while (digits > 0)
	{
		*(result + digits - 1) = ((n % 10) * -1) + '0';
		n = n / 10;
		digits--;
	}
	return (head);
}
