/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:12:29 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:10:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		len;

	len = ft_strlen(s1);
	result = (char *)malloc(sizeof(*result) * (len + 1));
	if (result == NULL)
		return (NULL);
	*((char *)ft_memcpy_at(result, s1, len)) = '\0';
	return (result);
}
