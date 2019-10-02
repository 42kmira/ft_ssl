/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:45:38 by kmira             #+#    #+#             */
/*   Updated: 2019/02/15 21:42:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_ptr;

	while ((*alst))
	{
		next_ptr = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = next_ptr;
	}
}
