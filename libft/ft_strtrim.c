/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:49:01 by kmira             #+#    #+#             */
/*   Updated: 2019/02/15 23:15:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespacep(int c)
{
	char *whitespaces;

	whitespaces = " \t\n\0";
	while (*whitespaces)
		if (c == *whitespaces++)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;
	char	*result;
	char	*head;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (is_whitespacep(*(s + end - 1)))
		end--;
	while (is_whitespacep(*s) && ++start)
		s++;
	if (start > end)
		start = end;
	result = malloc(sizeof(*result) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	head = result;
	while (start < end && ++start)
		*result++ = *s++;
	*result = '\0';
	return (head);
}
