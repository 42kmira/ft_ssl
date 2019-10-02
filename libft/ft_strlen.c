/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:28:06 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:14:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (1)
	{
		if (str[0] == '\0')
			return (str - start);
		if (str[1] == '\0')
			return (str - start + 1);
		if (str[2] == '\0')
			return (str - start + 2);
		if (str[3] == '\0')
			return (str - start + 3);
		if (str[4] == '\0')
			return (str - start + 4);
		if (str[5] == '\0')
			return (str - start + 5);
		if (str[6] == '\0')
			return (str - start + 6);
		if (str[7] == '\0')
			return (str - start + 7);
		if (str[8] == '\0')
			return (str - start + 8);
		str += 9;
	}
}
