/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:09:52 by kmira             #+#    #+#             */
/*   Updated: 2019/02/24 11:49:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_seen_at;

	last_seen_at = NULL;
	while (1)
	{
		if (s[0] == c)
			last_seen_at = (char *)s;
		if (s[0] == '\0')
			return (last_seen_at);
		if (s[1] == c)
			last_seen_at = (char *)(s + 1);
		if (s[1] == '\0')
			return (last_seen_at);
		if (s[2] == c)
			last_seen_at = (char *)(s + 2);
		if (s[2] == '\0')
			return (last_seen_at);
		if (s[3] == c)
			last_seen_at = (char *)(s + 3);
		if (s[3] == '\0')
			return (last_seen_at);
		s += 4;
	}
}
