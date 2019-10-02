/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:03:06 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 21:59:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** To Future me:
** Needs to be changed to a better implentation.
*/

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int num;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		num = -1 * nb;
	}
	else
		num = nb;
	if (num < 10 && (num = num + '0'))
		ft_putchar_fd(num, fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		num = (num % 10) + '0';
		ft_putchar_fd(num, fd);
	}
}
