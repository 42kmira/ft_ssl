/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:30:02 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:15:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t len;

	len = ft_min(ft_strlen(s1) + 1, ft_strlen(s2) + 1);
	len = ft_min(len, n);
	return (ft_memcmp(s1, s2, len));
}
