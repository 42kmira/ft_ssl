/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:26:28 by kmira             #+#    #+#             */
/*   Updated: 2019/02/15 22:36:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*head;

	if (s == NULL)
		return (NULL);
	result = malloc(sizeof(*result) * (len + 1));
	if (result == NULL)
		return (NULL);
	head = result;
	while (start-- > 0)
		s++;
	while (len-- > 0)
	{
		*result = *s;
		s++;
		result++;
	}
	*result = '\0';
	return (head);
}
