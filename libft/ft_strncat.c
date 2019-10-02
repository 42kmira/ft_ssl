/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:57:54 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:15:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*head;

	head = s1;
	s1 = ft_str_go_to_end(s1);
	*((char *)ft_memcpy_at(s1, s2,
			ft_fast_find(s2, n, '\0') - s2)) = '\0';
	return (head);
}
