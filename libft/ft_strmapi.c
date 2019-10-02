/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:26:15 by kmira             #+#    #+#             */
/*   Updated: 2019/02/15 22:30:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	char	*head;

	if (!(s) || !(f))
		return (NULL);
	result = malloc(sizeof(*result) * (ft_strlen(s) + 1));
	head = result;
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		*result = f((result - head), *s);
		result++;
		s++;
	}
	*result = '\0';
	return (head);
}
