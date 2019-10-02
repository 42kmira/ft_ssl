/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:35:29 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:12:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Needs to be changed.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	char			*head;
	unsigned int	total_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(*result) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	head = result;
	while (*s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2)
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (head);
}
