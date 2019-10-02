/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:06:02 by kmira             #+#    #+#             */
/*   Updated: 2019/02/15 22:25:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	s_len;
	char	*result;
	char	*head;

	if (!(s) || !(f))
		return (NULL);
	s_len = ft_strlen(s);
	result = malloc(sizeof(*result) * (s_len + 1));
	if (result == NULL)
		return (NULL);
	head = result;
	while (*s)
	{
		*result = f(*s);
		s++;
		result++;
	}
	*result = '\0';
	return (head);
}
