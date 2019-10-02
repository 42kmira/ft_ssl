/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:55:21 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:42:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the first pointer which points to ('\0' or char c)
** in str, whichever comes first.
*/

#include "libft.h"

const char	*ft_fast_find(const char *str, size_t range, int c)
{
	while (1)
	{
		if (str[0] == (char)c || str[0] == '\0' || range == 0)
			return (str);
		if (str[1] == (char)c || str[1] == '\0' || range == 1)
			return (str + 1);
		if (str[2] == (char)c || str[2] == '\0' || range == 2)
			return (str + 2);
		if (str[3] == (char)c || str[3] == '\0' || range == 3)
			return (str + 3);
		if (str[4] == (char)c || str[4] == '\0' || range == 4)
			return (str + 4);
		if (str[5] == (char)c || str[5] == '\0' || range == 5)
			return (str + 5);
		if (str[6] == (char)c || str[6] == '\0' || range == 6)
			return (str + 6);
		if (str[7] == (char)c || str[7] == '\0' || range == 7)
			return (str + 7);
		if (str[8] == (char)c || str[8] == '\0' || range == 8)
			return (str + 8);
		if (str[9] == (char)c || str[9] == '\0' || range == 9)
			return (str + 9);
		str += 10;
		range -= 10;
	}
}
