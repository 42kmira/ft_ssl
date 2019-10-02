/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:53:45 by kmira             #+#    #+#             */
/*   Updated: 2019/02/23 22:06:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Note to future self:
** Needs to be changed to be self dependent.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	return (ft_strncat(s1, s2, ft_strlen(s2) + 1));
}
