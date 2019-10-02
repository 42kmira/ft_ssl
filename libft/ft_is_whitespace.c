/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:23:12 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 19:38:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_whitespace(int c)
{
	char *whitespaces;

	whitespaces = " \t\n\v\f\r\0";
	while (*whitespaces)
		if (c == *whitespaces++)
			return (1);
	return (0);
}
