/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_go_to_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:11:14 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:04:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** String goes go the end and then returns the pointer where the null
** character is in the string. Useful for being able to add to the string.
*/

char	*ft_str_go_to_end(const char *str)
{
	const char	*start;

	start = str;
	while (1)
	{
		if (str[0] == '\0')
			return ((char *)str);
		if (str[1] == '\0')
			return ((char *)str + 1);
		if (str[2] == '\0')
			return ((char *)str + 2);
		if (str[3] == '\0')
			return ((char *)str + 3);
		if (str[4] == '\0')
			return ((char *)str + 4);
		if (str[5] == '\0')
			return ((char *)str + 5);
		if (str[6] == '\0')
			return ((char *)str + 6);
		if (str[7] == '\0')
			return ((char *)str + 7);
		if (str[8] == '\0')
			return ((char *)str + 8);
		str += 9;
	}
}
