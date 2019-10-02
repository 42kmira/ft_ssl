/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:55:00 by kmira             #+#    #+#             */
/*   Updated: 2019/02/18 23:37:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *f_list;
	t_list *fut_list;
	t_list *head;

	if (lst == NULL || !(f_list = ft_lstnew(NULL, 0)))
		return (NULL);
	f_list = f(lst);
	head = f_list;
	while (lst->next)
	{
		lst = lst->next;
		fut_list = f(lst);
		f_list->next = fut_list;
		f_list = fut_list;
	}
	return (head);
}
